#pragma once

#include "Builder.hpp"

class builderConcrete: public builder{
    public:
    builderConcrete();
    virtual void reset();
    virtual void buildWalls();
    virtual void buildDoor();
    virtual void buildWindows();
    virtual ~builderConcrete();
};