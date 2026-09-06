#include "InsuranceDecorator.h"

InsuranceDecorator::InsuranceDecorator(FilmProductionComp* comp, double insuranceCost) : TaskDecorator(comp), insuranceCost(insuranceCost){}

InsuranceDecorator::~InsuranceDecorator(){}

double InsuranceDecorator::getBudget() const {
    return wrapped->getBudget() + insuranceCost;
}

double InsuranceDecorator::getTime() const {
    return wrapped->getTime();
}