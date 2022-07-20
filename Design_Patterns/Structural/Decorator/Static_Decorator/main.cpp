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


struct Square : shape {
    int size{0};

    Square(int size):size(size){

    }

    string str() const {
        ostringstream oss;
        oss<<"The square has a size of "<<size;
        return oss.str();
    }

    void resize(int ratio){
        size *= ratio;
    }

};


template <typename T>
concept isShape = std::is_base_of<shape,T>::value;

template <isShape T>
struct ColoredShape:T{ // mixing inheritance
    string color;

    ColoredShape(){}

    template <typename...Args>
    ColoredShape(const string& str, Args...args):
                color(str),T(std::forward<Args>(args)...) //perfect forwarding
    {

    }

    string str() const{
        ostringstream oss;
        oss<<T::str()<<" has color "<<color;
        return oss.str();
    }

};

template <isShape T>
struct TransparencyShape:T{
    float transparency;

    TransparencyShape(){}

    template <typename...Args>
    TransparencyShape(float trans, Args...args):transparency(trans),T(std::forward<Args>(args)...)
    {

    }

    string str() const{
        ostringstream oss;
        oss<<T::str()<<" has transparency "<<transparency * 100 / 255<<"%";
        return oss.str();
    }

};



int main(){

   ColoredShape<Square> bluesquare{"Blue",10};

   cout<<bluesquare.str()<<endl;

   bluesquare.resize(5);

   cout<<bluesquare.str()<<endl;

   TransparencyShape<ColoredShape<Square>> transredsqr{100,"red",5};

   cout<<transredsqr.str()<<endl;




    return 0;
}