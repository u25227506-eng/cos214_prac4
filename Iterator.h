#pragma once

#include "FilmProductionComp.h"

class Iterator {
public:
    virtual ~Iterator();

    virtual bool hasNext() = 0;
    virtual void first() = 0;
    virtual void next() = 0;
    virtual FilmProductionComp* current() = 0;
};