#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Builder.hpp"
#include "Product.hpp"
#include "BuilderWood.hpp"
#include "BuilderConcrete.hpp"
#include "Director.hpp"

using namespace std;


int main(){

    builder *builder1 = new builderConcrete();
    Director *newDirector = new Director();
    newDirector->setBuilder(builder1);
    newDirector->makeProduct();
    Product p = builder1->getProduct();
    cout<<p<<endl; 
    delete builder1;
    delete newDirector;

    return 0;
}