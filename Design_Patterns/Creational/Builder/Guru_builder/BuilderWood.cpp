
#include "BuilderWood.hpp"
#include "Product.hpp"
#include <iostream>

using namespace std;

builderWood::builderWood(){
    product = new Product();
    product->mate = Material::Wood;
    this->reset();
}

void builderWood::reset(){
    product->doors = 0;
    product->walls = 0;
    product->windows = 0;
}

void builderWood::buildDoor(){
    cout<<"build Wood door"<<endl;
    product->doors = 2;
}

void builderWood::buildWalls(){
    cout<<"build wood walls"<<endl;
    product->walls = 5;
}

void builderWood::buildWindows(){
    cout<<"build windows of wood"<<endl;
    product->windows = 3;
}

builderWood::~builderWood(){
    cout<<"destroying wood product"<<endl;
    delete product;
}