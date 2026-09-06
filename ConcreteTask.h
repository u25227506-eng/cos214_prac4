#ifndef CONCRETETASK_H
#define CONCRETETASK_H

#include "FilmProductionComp.h"

class TaskState;

class ConcreteTask : public FilmProductionComp{
    private: 
        double budget;
        double time;
        TaskState* state;

    public: 
        ConcreteTask(const std::string& name, double budget, double time);
        ~ConcreteTask();
        double getBudget() const override;
        double getTime() const override;

        void start();
        void finish();
        void delay();

        void setState(TaskState* newState);
        std::string getStateName() const;
};

#endif //CONCRETETASK_H