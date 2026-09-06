#ifndef TASKDECORATOR_H
#define TASKDECORATOR_H

#include "FilmProductionComp.h"

class TaskDecorator : public FilmProductionComp{
    protected:
        FilmProductionComp* wrapped;
    public:     
        TaskDecorator(FilmProductionComp* comp);
        virtual ~TaskDecorator();

        std::string getName() const override;
        void start() override;
        void finish() override;
        void delay() override;
        std::string getStateName() const override;

};

#endif //TASKDECORATOR_H