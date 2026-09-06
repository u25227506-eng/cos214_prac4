#ifndef PHASECOMPOSITE_H
#define PHASECOMPOSITE_H

#include "FilmProductionComp.h"
#include <vector>

class PhaseComposite : public FilmProductionComp {
    protected: 
        std::vector<FilmProductionComp*> children;

    public: 
        PhaseComposite(const std::string& name);
        virtual ~PhaseComposite();

        void add(FilmProductionComp* comp) override;
        void remove(FilmProductionComp* comp) override;
        FilmProductionComp* getChild(int index) override;

        int getSize() const;
        bool isEmpty() const;

        double getBudget() const override;
        double getTime() const override;
};

#endif //PHASECOMPOSITE_H