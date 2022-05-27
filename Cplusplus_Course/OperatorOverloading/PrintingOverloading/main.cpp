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

    friend ostream &operator<<(ostream &out,Test &other){
        out << other.id <<", "<<other.name<<", "<<*(other.size)<<endl;
        return out;
    }

};

int main(int argc, char const *argv[])
{
   Test test1(10,"test1",25.5);
   //test1.print();

   cout<<test1<<endl;



    return 0;
}
