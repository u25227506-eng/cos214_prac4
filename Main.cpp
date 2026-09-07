#include <iostream>
#include "PreProductionPhase.h"
#include "ProductionPhase.h"
#include "PostProductionPhase.h"

#include "PreProductionPhaseIterator.h"
#include "ProductionPhaseIterator.h"
#include "PostProductionPhaseIterator.h"

#include "ScreenWriting.h"
#include "StoryBoarding.h"
#include "Makeup.h"
#include "Recording.h"
#include "Mixing.h"
#include "Editing.h"

#include "InsuranceDecorator.h"
#include "OvertimeDecorator.h"

void printPhase(const std::string& phaseName, Iterator* it) {
    std::cout << "--- " << phaseName << " ---" << std::endl;
    for (it->first(); it->hasNext(); it->next()) {
        FilmProductionComp* task = it->current();
        std::cout << task->getName()
                  << " | Budget: " << task->getBudget()
                  << " | Time: " << task->getTime()
                  << " | State: " << task->getStateName()
                  << std::endl;
    }
    delete it;
}

int main() {
    // --- Build the three top-level phases (composites own their children) ---
    PreProductionPhase preProduction("Pre-Production");
    ProductionPhase production("Production");
    PostProductionPhase postProduction("Post-Production");

    // --- Build plain tasks on the heap ---
    ScreenWriting* screenWriting = new ScreenWriting("Screen Writing", 5000.0, 14.0);
    StoryBoarding* storyBoarding = new StoryBoarding("Story Boarding", 3000.0, 7.0);
    Recording* recording = new Recording("Recording", 20000.0, 30.0);
    Mixing* mixing = new Mixing("Mixing", 8000.0, 10.0);
    Makeup* makeup = new Makeup("Makeup", 4000.0, 20.0);
    Editing* editing = new Editing("Editing", 15000.0, 25.0);

    // --- DECORATOR STACKING ---
    // Recording gets wrapped in TWO decorators, stacked: insurance first,
    // then overtime on top of that. Only the OUTERMOST wrapper
    // (decoratedRecording) gets added to the composite - the composite
    // never needs to know it's decorated, since it's still just a
    // FilmProductionComp* as far as add()/getBudget()/getTime() are concerned.
    FilmProductionComp* recordingWithInsurance = new InsuranceDecorator(recording, 500.0);
    FilmProductionComp* decoratedRecording = new OvertimeDecorator(recordingWithInsurance, 2000.0, 5.0);

    // --- NESTED SUB-PHASE: "Second Unit" ---
    // Domain justification: large productions run a second unit crew that
    // shoots supplementary footage (pickup shots, stunts, inserts) in
    // parallel with the main unit, during the same overall Production
    // phase. It's a genuine nested GROUP (not just another task) - it has
    // its own tasks and its own sub-budget, and its totals roll up into
    // Production's totals via the same recursive getBudget()/getTime().
    // This gives the hierarchy a real third level of nesting:
    //   main -> Production -> SecondUnit -> (its own tasks)
    ProductionPhase* secondUnit = new ProductionPhase("Second Unit");
    Mixing* secondUnitMixing = new Mixing("Second Unit Mixing", 2000.0, 5.0);
    secondUnit->add(secondUnitMixing);

    // --- Assemble the composite tree ---
    preProduction.add(screenWriting);
    preProduction.add(storyBoarding);

    production.add(decoratedRecording); // stacked decorator added here, not raw recording
    production.add(mixing);
    production.add(makeup);
    production.add(secondUnit); // PhaseComposite accepts any FilmProductionComp*,
                                  // including another PhaseComposite - a phase can
                                  // legally contain another phase with no special-casing.

    postProduction.add(editing);

    // --- Exercise the State pattern ---
    screenWriting->start();
    screenWriting->finish();

    storyBoarding->start();

    recording->start(); // state lives on the underlying ConcreteTask;
    recording->delay();  // decorators forward getStateName()/getBudget()/getTime()
                          // down to it rather than duplicating state logic

    editing->finish(); // invalid transition: finishing before starting

    // --- TWO INDEPENDENT TRAVERSALS OVER THE SAME STRUCTURE ---
    // Both iterators are created from the SAME production phase and
    // advanced independently, proving one doesn't affect the other's
    // position - separate index state, not a shared cursor.
    std::cout << "\n--- Two independent iterators over Production ---" << std::endl;
    Iterator* iteratorA = production.createIterator();
    Iterator* iteratorB = production.createIterator();

    iteratorA->first();
    iteratorB->first();
    iteratorB->next(); // manually move iteratorB one step ahead of iteratorA

    std::cout << "iteratorA at: " << iteratorA->current()->getName() << std::endl;
    std::cout << "iteratorB at: " << iteratorB->current()->getName() << std::endl;

    delete iteratorA;
    delete iteratorB;

    // --- Full traversal of each top-level phase ---
    printPhase("Pre-Production", preProduction.createIterator());
    printPhase("Production", production.createIterator());
    printPhase("Post-Production", postProduction.createIterator());

    // --- NOTE ON ITERATION SCOPE ---
    // PreProductionPhaseIterator / ProductionPhaseIterator /
    // PostProductionPhaseIterator each walk only their DIRECT children -
    // they do NOT recurse into a nested phase automatically. Iterating
    // `production` shows "Second Unit" as a single entry (its own
    // getBudget()/getTime() already sum its own children), not expanded
    // into SecondUnit's tasks individually. This is a deliberate scope
    // decision: each concrete iterator's job is to traverse ONE phase's
    // own children, mirroring how a production manager reviews one
    // unit's task list at a time rather than a flattened view of the
    // whole production. Getting SecondUnit's own task-level detail means
    // calling secondUnit.createIterator() explicitly - itself an example
    // of two meaningfully different traversal behaviours (whole-phase
    // view vs. drill-into-subgroup view).
    printPhase("Second Unit (drill-down)", secondUnit->createIterator());

    // --- RUNTIME STRUCTURAL CHANGE, WITH DOCUMENTED TRAVERSAL POLICY ---
    // Policy: iterators in this system are LIVE views over the composite's
    // internal vector (they store an index, not a copy of the data).
    // Because of this, structural changes (add/remove) must only happen
    // when no iterator is currently mid-traversal over that phase. Any
    // iterator created BEFORE a structural change is treated as stale and
    // discarded; a NEW iterator must be created afterward to see the
    // updated structure. We do not support modifying a phase while an
    // iterator on it is still in use.
    //
    // Demonstration: move "makeup" out of Production and into
    // Post-Production, after all prior iterators on Production have
    // already finished and been deleted (printPhase deletes its iterator
    // internally, and the two independent iterators above were already
    // deleted before this point).
    std::cout << "\n--- Structural change: moving Makeup to Post-Production ---" << std::endl;
    production.remove(makeup);
    postProduction.add(makeup);

    // A fresh iterator correctly reflects the new structure:
    printPhase("Production (after move)", production.createIterator());
    printPhase("Post-Production (after move)", postProduction.createIterator());

    // --- Totals (composite sums recursively over children, including
    //     decorated ones and the nested Second Unit sub-phase) ---
    std::cout << "\n--- Totals ---" << std::endl;
    std::cout << "Pre-Production budget: " << preProduction.getBudget()
              << ", time: " << preProduction.getTime() << std::endl;
    std::cout << "Production budget: " << production.getBudget()
              << ", time: " << production.getTime() << std::endl;
    std::cout << "Post-Production budget: " << postProduction.getBudget()
              << ", time: " << postProduction.getTime() << std::endl;

    // No manual delete needed for tasks - each phase's destructor deletes
    // its own children exactly once. decoratedRecording is deleted via
    // production's destructor, which cascades: ~OvertimeDecorator deletes
    // recordingWithInsurance, whose ~InsuranceDecorator deletes recording.
    // secondUnit is stack-allocated in main() and NOT added by pointer-
    // ownership transfer issues, since production only stores a raw
    // FilmProductionComp* to it and never deletes it directly - see the
    // ownership note below.
    return 0;
}