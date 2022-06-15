#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

enum class PointType{
    cartessian,
    polar
};


struct Point{
    float x, y;
    Point(float x, float y):x(x),y(y){

    }
    // this is not posible in c++, to have 2 constructors with the same signature
    /*Point (float rho, float tetha){
        x = rho * cos(tetha);
        y = rho * sin(tetha);
    }*/

    //a possible solution coul be adding a new parameter to especify if we are using cartessian or polar coordinates

    Point(float a, float b, PointType type){
        if(type == PointType::cartessian){
            x = a;
            y = b;
        }else{
            x = a * cos(b);
            y = a * sin(b);
        }
    }

};

// BUT A BETTER SOLUTION IN THIS CASE SHOULD BE A FACTORY 

int main(){





    return 0;
}