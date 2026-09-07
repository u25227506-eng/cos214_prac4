#pragma once

#include "FilmProductionComp.h"
#include "TaskState.h"

class TaskDecorator : public FilmProductionComp {
protected:
    FilmProductionComp* Comp;
    TaskState* taskState;

    double extraBudget;
    double extraTime;

public:
    TaskDecorator(FilmProductionComp* comp, double budget, double time);
    virtual ~TaskDecorator();

    TaskState* getState();
    void setState(TaskState* taskState);

    void add(FilmProductionComp* comp) override;
    void remove(FilmProductionComp* comp) override;
    FilmProductionComp* getChild(int index) override;
    std::string getStateName() const override;

    double getBudget() const override;
    double getTime() const override;
};

