#include "PreProductionPhase.h"

PreProductionPhase::PreProductionPhase(const std::string& name) : PhaseComposite(name){}

PreProductionPhase::~PreProductionPhase() {
    //children get cleaned up by PhaseComposite destructor
}