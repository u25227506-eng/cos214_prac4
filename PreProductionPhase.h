#ifndef PREPRODUCTIONPHASE_H
#define PREPRODUCTIONPHASE_H

#include "PhaseComposite.h"

class PreProductionPhase : public PhaseComposite{
    public: 
        PreProductionPhase(const std::string& name);
        ~PreProductionPhase();
};

#endif //PREPRODUCTIONPHASE_H