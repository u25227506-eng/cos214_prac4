#ifndef PREPRODUCTIONPHASE_H
#define PREPRODUCTIONPHASE_H


#include "PhaseComposite.h"
#include "Iterator.h"

class PreProductionPhase : public PhaseComposite {
    public: 
        PreProductionPhase(const std::string& name);
        ~PreProductionPhase();
        Iterator* createIterator();
};

#endif //POSTPRODUCTIONPHASE_H