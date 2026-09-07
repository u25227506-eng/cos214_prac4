#pragma once

#include "Iterator.h"
#include "PreProductionPhase.h"
#include "FilmProductionComp.h"

class PreProductionPhaseIterator : public Iterator {
private:
    PreProductionPhase* phase; // the composite being iterated
    int index;                 // current position in phase's children

public:
    PreProductionPhaseIterator(PreProductionPhase* phase);
    ~PreProductionPhaseIterator();

    bool hasNext();
    void first();
    void next();
    FilmProductionComp* current();
};
