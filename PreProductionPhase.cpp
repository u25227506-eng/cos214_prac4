#include "PreProductionPhase.h"
#include "PreProductionPhaseIterator.h"

PreProductionPhase::PreProductionPhase(const std::string& name) : PhaseComposite(name){}

PreProductionPhase::~PreProductionPhase() {
    //children get cleaned up by PhaseComposite destructor
}

Iterator* PreProductionPhase::createIterator() {
    return new PreProductionPhaseIterator(this);
}