#pragma once

#include "Builder.hpp"

class Director{
    builder *builder1;
    public:

    void setBuilder(builder *builder);
    void makeProduct();
};