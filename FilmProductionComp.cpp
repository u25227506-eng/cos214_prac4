#include "FilmProductionComp.h"

FilmProductionComp::FilmProductionComp(const std::string& name) : name(name){}

FilmProductionComp::~FilmProductionComp(){}

void FilmProductionComp::add(FilmProductionComp* comp){
    //PhaseComposite overrides this
}

void FilmProductionComp::remove(FilmProductionComp* comp){

}

FilmProductionComp* FilmProductionComp::getChild(int index){
    return nullptr;
}

std::string FilmProductionComp::getName() const{
    return name;
}

void FilmProductionComp::start() {}
void FilmProductionComp::finish() {}
void FilmProductionComp::delay() {}

std::string FilmProductionComp::getStateName() const {
    return "";
}