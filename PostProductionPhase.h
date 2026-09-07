#ifndef POSTPRODUCTIONPHASE_H
#define POSTPRODUCTIONPHASE_H


#include "PhaseComposite.h"
#include "Iterator.h"

class PostProductionPhase : public PhaseComposite {
    public: 
        PostProductionPhase(const std::string& name);
        ~PostProductionPhase();
        Iterator* createIterator();
};

#endif //POSTPRODUCTIONPHASE_H