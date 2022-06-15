#pragma once

#include "HotDrinkFactory.hpp"
#include <functional>
#include <map>

using namespace std;

class DrinkFactory{
    map<string,unique_ptr<HotDrinkFactory>> mapHt;
    public:
    DrinkFactory(){
        mapHt["coffee"] = make_unique<CoffeeFactory>();
        mapHt["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink (string drink){
        auto dr = mapHt[drink]->make();
        dr->Prepare(100);
        return dr;
    }
};


class DrinkFactoryFunctional{
    map<string,function<unique_ptr<HotDrink>()>> factories;
    public:
        DrinkFactoryFunctional(){
            factories["tea"] = [] {
                auto fact = make_unique<TeaDrink>();
                fact->Prepare(250);
                return fact;
            };

            factories["coffee"] = [] {
                auto fact = make_unique<CoffeeDrink>();
                fact->Prepare(250);
                return fact;
            };
        }

        unique_ptr<HotDrink> make_drink (string drink){
            return factories[drink]();
        }

};