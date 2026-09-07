#include "ProductionPhaseIterator.h"

ProductionPhaseIterator::ProductionPhaseIterator(ProductionPhase* phase) {
    this->phase = phase;
    this->index = 0;
}

ProductionPhaseIterator::~ProductionPhaseIterator() {
}

void ProductionPhaseIterator::first() {
    index = 0;
}

bool ProductionPhaseIterator::hasNext() {
    return index < phase->getSize();
}

void ProductionPhaseIterator::next() {
    index++;
}

FilmProductionComp* ProductionPhaseIterator::current() {
    if (hasNext()) {
        return phase->getChild(index);
    }
    
}