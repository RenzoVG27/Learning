#include <iostream>
#include <stdio.h>

using namespace std;

class Test{
    int id;
    string name;
    float *size;


    public:
    Test():id(0),name(""),size(new float(3.0)){

    }

    Test(int id,string name,float size):id(id),name(name),size(new float(size)){

    }

    Test (const Test & other){
        cout<<"Copy constructor"<<endl;
        size = new float;
        *this = other;
    }

    void print(){
        cout<<id<<": "<<name<<","<<*size<<endl;
    }

    const Test& operator=(const Test& other){
        cout<<"Assignment operator"<<endl;

        id = other.id;
        name = other.name;
        (*size) = *(other.size);

        return *this;
    }

    void SetSize(float size){
        *(this->size) = size;
    }

};

int main(int argc, char const *argv[])
{
   Test test1(10,"test1",10.0);
   test1.print();

   Test test2(30,"bob",20.0);
   test2.print();

   Test test3;

cout<<"----------"<<endl;

    test1 = test2;
    test1.print();
    test2.print();

    test3.operator=(test2);
    cout<<"Print test3"<<endl;
    test3.print();

    cout<<"Print test4"<<endl;
    Test test4 = test1;
    test4.print();

    cout<<"Change test2"<<endl;
    test2.SetSize(55.5);
    test2.print();

    cout<<"Print test1,3,4"<<endl;
    test1.print();
    test3.print();
    test4.print();

    


    return 0;
}
