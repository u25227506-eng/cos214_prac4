#include "PhaseComposite.h"

PhaseComposite::PhaseComposite(const std::string& name) : FilmProductionComp(name) {}

PhaseComposite::~PhaseComposite(){
    for (FilmProductionComp* child : children){
        delete child;
    }
    children.clear();
}

void PhaseComposite::add(FilmProductionComp* comp){
    children.push_back(comp);
}

void PhaseComposite::remove(FilmProductionComp* comp){
    for (int i =0; i < (int)children.size(); i++){
        if (children[i] == comp){
            children.erase(children.begin() + i);
            break;
            //only detach in cases of moving this comp to anotherr phase so u can just add() it there
        }
    }
}

FilmProductionComp* PhaseComposite::getChild(int index){
    if (index < 0 || index >= static_cast<int>(children.size())){
        return nullptr;
    }
    return children[index];
}

int PhaseComposite::getSize() const {
    return static_cast<int>(children.size());
}

bool PhaseComposite::isEmpty() const {
    return children.empty();
}

double PhaseComposite::getBudget() const{
    double total = 0.0;
    for (int i = 0; i < (int)children.size(); i++){
        total += children[i]->getBudget();
    }
    return total;
}

double PhaseComposite::getTime() const{
    double total = 0.0;
    for (int i =0; i < (int)children.size(); i++){
        total += children[i]->getTime();
    }
    return total;
}