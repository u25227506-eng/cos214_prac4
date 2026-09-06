#include "ProductionPhase.h"

ProductionPhase::ProductionPhase(const std::string& name) : PhaseComposite(name){}

ProductionPhase::~ProductionPhase(){
    //cleaned up by PhaseComposite destructor then
}
