#pragma once

#include "Product.hpp"

enum class Material{
    Wood,
    Concrete
};

class builder{

    public:

    Product *product;

    virtual void reset()= 0;
    virtual void buildWalls() = 0;
    virtual void buildDoor() = 0;
    virtual void buildWindows() = 0;

    inline Product getProduct() {return *product;}

    inline const Material getType() { return product->mate;}

    virtual ~builder() {};

};