#include "PostProductionPhase.h"
#include "PostProductionPhaseIterator.h"

PostProductionPhase::PostProductionPhase(const std::string& name) : PhaseComposite(name){}

PostProductionPhase::~PostProductionPhase() {
    
}

Iterator* PostProductionPhase::createIterator() {
    return new PostProductionPhaseIterator(this);
}