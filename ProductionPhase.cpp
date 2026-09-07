#include "ProductionPhase.h"
#include "ProductionPhaseIterator.h"

ProductionPhase::ProductionPhase(const std::string& name) : PhaseComposite(name){}

ProductionPhase::~ProductionPhase(){
    //cleaned up by PhaseComposite destructor then
}


Iterator* ProductionPhase::createIterator() {
    return new ProductionPhaseIterator(this);
}