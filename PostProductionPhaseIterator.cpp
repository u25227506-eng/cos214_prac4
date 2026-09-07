#include "PostProductionPhaseIterator.h"

PostProductionPhaseIterator::PostProductionPhaseIterator(PostProductionPhase* phase) {
    this->phase = phase;
    this->index = 0;
}

PostProductionPhaseIterator::~PostProductionPhaseIterator() {
}

void PostProductionPhaseIterator::first() {
    index = 0;
}

bool PostProductionPhaseIterator::hasNext() {
    return index < phase->getSize();
}

void PostProductionPhaseIterator::next() {
    index++;
}

FilmProductionComp* PostProductionPhaseIterator::current() {
    if (hasNext()) {
        return phase->getChild(index);
    }
    
}