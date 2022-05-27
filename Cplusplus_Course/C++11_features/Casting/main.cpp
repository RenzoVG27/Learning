#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;


class Car{

    public:

    Car(){
        cout<<"Consturctor Car"<<endl;
    }

     virtual void print(){
        cout<<"Hello Car: "<<this<<endl;
    }
};

class Suv: public Car{
    public:
    int a{100};

    Suv(){
        cout<<"Consturctor Suv"<<endl;
    }
    void print(){
        cout<<"Hello Suv: "<<a<<endl;
    }

    void Own(){
        cout<<"Suv owns"<<endl;
    }
};

class Mini: public Car{
    public:
    float b{12.5};

    Mini(){
        cout<<"Consturctor Mini"<<endl;
    }

    void print(){
        cout<<"Hello Mini: "<<b<<endl;
    }
    void Own(){
        cout<<"Mini owns"<<endl;
    }
};

int main(int argc, char const *argv[])
{

    Car newCar;
    Mini newMini;

    Car *myCar = &newMini;
    myCar->print();

    Suv *newSuv = dynamic_cast<Suv *>(myCar);
    if(newSuv==nullptr){
        cout<<"Invalid Cast"<<endl;
    }else{
        newSuv->print();
        newSuv->Own();
    }
    

    Mini *miniCar = dynamic_cast<Mini *>(myCar);
    if(miniCar == nullptr){
        cout<<"invalid cast!!"<<endl;
    }else{
        miniCar->print();
    }


    char c = 10;
    int *newint = static_cast<int*>(&c); //invalid because of number of bytes

    *newint = 500;

    cout<<"new int: "<<*newint<<endl;

    
    
    return 0;
}
