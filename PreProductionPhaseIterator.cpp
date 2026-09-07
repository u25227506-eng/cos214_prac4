#include "PreProductionPhaseIterator.h"

PreProductionPhaseIterator::PreProductionPhaseIterator(PreProductionPhase* phase) {
    this->phase = phase;
    this->index = 0;
}

PreProductionPhaseIterator::~PreProductionPhaseIterator() {
}

void PreProductionPhaseIterator::first() {
    index = 0;
}

bool PreProductionPhaseIterator::hasNext() {
    return index < phase->getSize();
}

void PreProductionPhaseIterator::next() {
    index++;
}

FilmProductionComp* PreProductionPhaseIterator::current() {
    if (hasNext()) {
        return phase->getChild(index);
    }
    
}