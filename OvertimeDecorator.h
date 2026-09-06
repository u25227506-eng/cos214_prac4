#ifndef OVERTIMEDECORATOR_H
#define OVERTIMEDECORATOR_H

#include "TaskDecorator.h"

class OvertimeDecorator : public TaskDecorator{
    private:
        double extraCost;
        double extraTime;

    public: 
        OvertimeDecorator(FilmProductionComp* comp, double extraCost, double extraTime);
        ~OvertimeDecorator();

        double getBudget() const override;
        double getTime() const override;
};

#endif //OVERTIMEDECORATOR_H