#include "OvertimeDecorator.h"

OvertimeDecorator::OvertimeDecorator(FilmProductionComp* comp, double extraCost, double extraTime)
    : TaskDecorator(comp, extraCost, extraTime) {
}

OvertimeDecorator::~OvertimeDecorator() {
}

double OvertimeDecorator::getBudget() const {
    return TaskDecorator::getBudget();
}

double OvertimeDecorator::getTime() const {
    return TaskDecorator::getTime();
}