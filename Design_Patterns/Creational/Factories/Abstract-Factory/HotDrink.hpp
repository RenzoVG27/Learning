#pragma once

using namespace std;

struct HotDrink{
    virtual void Prepare(int volumen) const = 0;
};

struct TeaDrink : HotDrink{
    void Prepare (int volumen) const override{
        cout<<"Pour "<<volumen<<" of Tea"<<endl;
    }
};

struct CoffeeDrink : HotDrink{
    void Prepare (int volumen) const override{
        cout<<"Pour "<<volumen<<" of Coffee"<<endl;
    }
};