#ifndef INSURANCEDECORATOR_H
#define INSURANCEDECORATOR_H

#include "TaskDecorator.h"

class InsuranceDecorator : public TaskDecorator{
    private: 
        double insuranceCost;
    
    public:
        InsuranceDecorator(FilmProductionComp* comp, double insuranceCost);
        ~InsuranceDecorator();
        double getBudget() const override;
        double getTime() const override;
};

#endif //INSURANCEDECORATOR_H