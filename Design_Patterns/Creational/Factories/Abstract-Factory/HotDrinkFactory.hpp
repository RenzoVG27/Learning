#pragma once

#include "HotDrink.hpp"
#include <memory>


using namespace std;

struct HotDrinkFactory{//AF
    virtual unique_ptr<HotDrink> make () const = 0;
};

struct TeaFactory: HotDrinkFactory{
    unique_ptr<HotDrink> make () const {
        return make_unique<TeaDrink>();
    }
};


struct CoffeeFactory: HotDrinkFactory{
    unique_ptr<HotDrink> make () const {
        return make_unique<CoffeeDrink>();
    }
};
