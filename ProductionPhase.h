#ifndef PRODUCTIONPHASE_H
#define PRODUCTIONPHASE_H

#include "PhaseComposite.h"

class ProductionPhase : public PhaseComposite{
    public: 
        ProductionPhase(const std::string& name);
        ~ProductionPhase();
};

#endif //PRODUCTIONPHASE_H