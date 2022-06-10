#include "Director.hpp"
#include "Builder.hpp"

void Director::setBuilder(builder *builder1){
    this->builder1 = builder1;
}

void Director::makeProduct(){
    builder1->reset();
    if(builder1->getType() == Material::Wood)
    {
        builder1->buildWalls();
        builder1->buildWindows();
        builder1->buildDoor();
    }
    else
    {
        builder1->buildWalls();
        builder1->buildDoor();
    }
}