#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;

//This pattern is used to add funtionality to an object without modifying it (Closed open principle)


struct shape
{
    virtual string str() const = 0;
};

struct Circle: shape{
    float radius{0};
    Circle()  = default;
    Circle(float rad) : radius(rad){

    }

    string str() const {
        ostringstream oss;
        oss<<"The circle has an radius of "<<radius;
        return oss.str();
    }

};


struct Square : shape {
    int size{0};

    Square(int size):size(size){

    }

    string str() const {
        ostringstream oss;
        oss<<"The square has a size of "<<size;
        return oss.str();
    }

};

struct Coloredshape: shape{
    shape &ownshape;
    string color;

    Coloredshape(shape& sha,const string color):ownshape(sha),color(color){

    }

    string str() const {
        ostringstream oss;
        oss<<ownshape.str()<<" has color "<<color;
        return oss.str();
    }
};


int main(){

   Circle mycircle{3};

   cout<<mycircle.str()<<endl;

   Coloredshape colorshaped{mycircle,"Red"};

   cout<<colorshaped.str()<<endl;


    return 0;
}