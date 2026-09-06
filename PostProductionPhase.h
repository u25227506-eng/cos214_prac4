#ifndef POSTPRODUCTIONPHASE_H
#define POSTPRODUCTIONPHASE_H


#include "PhaseComposite.h"

class PostProductionPhase : public PhaseComposite {
    public: 
        PostProductionPhase(const std::string& name);
        ~PostProductionPhase();
};

#endif //POSTPRODUCTIONPHASE_H