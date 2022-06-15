#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "HotDrinkFactory.hpp"
#include "HotDrink.hpp"
#include <memory>

#include "DrinkFactory.hpp"

using namespace std;

unique_ptr<HotDrink> make_drink (const string drink){
    unique_ptr<HotDrink> ht;

    if(drink == "tea"){
        ht = make_unique<TeaDrink>();
        ht->Prepare(200);
    }else{
        ht = make_unique<CoffeeDrink>();
        ht->Prepare(300);
    }
    return ht;
};

int main(){


    make_drink("tea");


    DrinkFactory df;

    df.make_drink("coffee");


    DrinkFactoryFunctional dff;

    dff.make_drink("coffee");
    


    return 0;
}