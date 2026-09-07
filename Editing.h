#pragma once

#include "ConcreteTask.h"

class Editing : public ConcreteTask {
public:
    Editing(const std::string& name, double budget, double time);
    ~Editing();
};

