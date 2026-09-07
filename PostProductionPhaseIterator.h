#pragma once

#include "Iterator.h"
#include "PostProductionPhase.h"
#include "FilmProductionComp.h"

class PostProductionPhaseIterator : public Iterator {
private:
    PostProductionPhase* phase; // the composite being iterated
    int index;                 // current position in phase's children

public:
    PostProductionPhaseIterator(PostProductionPhase* phase);
    ~PostProductionPhaseIterator();

    bool hasNext();
    void first();
    void next();
    FilmProductionComp* current();
};
