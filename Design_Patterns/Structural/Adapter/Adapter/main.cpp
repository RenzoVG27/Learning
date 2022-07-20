#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <memory>

using namespace std;

class Square{
    int side;

    public:

    Square(const int &side):side(side){}

    int getSide(){return side;}

};

class Rectangle{

    public:

    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
};

class SquaretoRectangleAdapter : public Rectangle{
    public :

    SquaretoRectangleAdapter(Square& square): square(square){
        
    }

    virtual int getWidth() const { return square.getSide();}
    virtual int getHeight() const { return square.getSide();}

    private:

    Square& square;


};


int CalculateArea(Rectangle &rect){

    return rect.getWidth() * rect.getHeight();

}

int main(){

    Square newsquare{15};
    SquaretoRectangleAdapter rectAdapt{newsquare};

    cout<<"Area is : "<< CalculateArea(rectAdapt)<<endl;


    return 0;
}