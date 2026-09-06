#include "OvertimeDecorator.h"

OvertimeDecorator::OvertimeDecorator(FilmProductionComp* comp, double extraCost, double extraTime) : TaskDecorator(comp), extraCost(extraCost), extraTime(extraTime){}

OvertimeDecorator::~OvertimeDecorator(){}

double OvertimeDecorator::getBudget() const{
    return wrapped->getBudget() + extraCost;
}

double OvertimeDecorator::getTime() const{
    return wrapped->getTime() + extraTime;
}