#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


class Parent {
    protected:
    int arg1;

    public:

    Parent():arg1(10){

    }

    Parent(const Parent& other){
        cout<<"Copy constructor"<<endl;
        arg1 = other.arg1;
    }

    virtual void print(){
        cout<<"Parent print: "<<arg1<<endl;
    }
};

class Child: public Parent{
    private:
    int arg2;

    public:

    Child():arg2(20){
        cout<<"Child constructor"<<endl;
    }

    Child (const Child& other){
        cout<<"Copy constructor child"<<endl;
        arg2 = other.arg2;
    }
    
    void print(){
        cout<<"Child print"<<arg2<<endl;
    }

};

int main(int argc, char const *argv[])
{

    Child c1;
    c1.print();
    Parent &p1 = c1;
    p1.print();

    Parent p2 = Child();
    p2.print();

    return 0;
}
