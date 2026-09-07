#include "InsuranceDecorator.h"

InsuranceDecorator::InsuranceDecorator(FilmProductionComp* comp, double insuranceCost)
    : TaskDecorator(comp, 0.0, 0.0), insuranceCost(insuranceCost) {
}

InsuranceDecorator::~InsuranceDecorator() {
}

double InsuranceDecorator::getBudget() const {
    return TaskDecorator::getBudget() + insuranceCost;
}

double InsuranceDecorator::getTime() const {
    return TaskDecorator::getTime();
}