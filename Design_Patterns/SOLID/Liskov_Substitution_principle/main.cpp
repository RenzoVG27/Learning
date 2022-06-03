#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Rectangle{
    protected:
    int width{0};
    int height{0};

    public:
    Rectangle(int width,int height):width(width),height(height){

    }

    virtual void setWidth(int width){
        this->width = width;
    }

    virtual void setHeight(int height){
        this->height = height;
    }

    int getWidth(){
        return width;
    }

    int getHeight(){
        return height;
    }

    int getArea(){
        return width*height;
    }

};

// This desing breaks the Liskov principle because when we replace 
//the derived class square into a process function the result changes from expected to real

class Square:public Rectangle{

    public:

    Square(int size):Rectangle(size,size){
        
    }

    virtual void setWidth(int width){
        this->width = this->height = width;
    }

    virtual void setHeight(int height){
        this->width = this->height = height;
    }
};

void Process(Rectangle & rect){
    int height = rect.getHeight();
    rect.setWidth(10);

    std::cout<<"Expected area : "<<10*height<<", got : "<<rect.getArea()<<std::endl;
}


int main(){

    Rectangle rect(3,4);
    Process(rect);

    Square sqr(5);
    Process(sqr);

    return 0;
}