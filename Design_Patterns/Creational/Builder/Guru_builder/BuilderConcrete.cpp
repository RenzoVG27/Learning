
#include "BuilderConcrete.hpp"
#include "Product.hpp"
#include <iostream>

using namespace std;

builderConcrete::builderConcrete(){
    product = new Product();
    product->mate = Material::Concrete;
    this->reset();
}

void builderConcrete::reset(){
    product->doors = 0;
    product->walls = 0;
    product->windows = 0;
}

void builderConcrete::buildDoor(){
    cout<<"build Concrete door"<<endl;
    product->doors = 3;
}

void builderConcrete::buildWalls(){
    cout<<"build Concrete walls"<<endl;
    product->walls = 7;
}

void builderConcrete::buildWindows(){
    cout<<"build windows of Concrete"<<endl;
    product->windows = 2;
}

builderConcrete::~builderConcrete(){
    cout<<"destroying concrete product"<<endl;
    delete product;
}