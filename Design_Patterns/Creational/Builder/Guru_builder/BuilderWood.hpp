#pragma once

#include "Builder.hpp"

class builderWood: public builder{
    public:
    builderWood();
    virtual void reset();
    virtual void buildWalls();
    virtual void buildDoor();
    virtual void buildWindows();
    virtual ~builderWood();
};