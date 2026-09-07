#ifndef PRODUCTIONPHASE_H
#define PRODUCTIONPHASE_H

#include "PhaseComposite.h"
#include "Iterator.h"

class ProductionPhase : public PhaseComposite{
    public: 
        ProductionPhase(const std::string& name);
        ~ProductionPhase();
        Iterator* createIterator();
};

#endif //PRODUCTIONPHASE_H