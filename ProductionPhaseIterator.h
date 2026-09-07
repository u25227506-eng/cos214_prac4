#pragma once

#include "Iterator.h"
#include "ProductionPhase.h"
#include "FilmProductionComp.h"

class ProductionPhaseIterator : public Iterator {
private:
    ProductionPhase* phase; // the composite being iterated
    int index;                 // current position in phase's children

public:
    ProductionPhaseIterator(ProductionPhase* phase);
    ~ProductionPhaseIterator();

    bool hasNext();
    void first();
    void next();
    FilmProductionComp* current();
};
