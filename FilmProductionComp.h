#ifndef FILMPRODUCTIONCOMP_H
#define FILMPRODUCTIONCOMP_H

#include <string> 

class FilmProductionComp{
    protected: 
        std::string name;

    public:
        FilmProductionComp(const std::string& name);
        virtual ~FilmProductionComp();
        virtual void add(FilmProductionComp* comp);
        virtual void remove(FilmProductionComp* comp);
        virtual FilmProductionComp* getChild(int index);

        virtual double getBudget() const = 0;
        virtual double getTime() const = 0;
        virtual std::string getName() const;

        virtual void start();
        virtual void finish();
        virtual void delay();
        virtual std::string getStateName() const;
};

#endif //FILMPRODUCTIONCOMP_H