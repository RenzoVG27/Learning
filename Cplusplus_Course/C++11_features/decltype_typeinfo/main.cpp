#include <iostream>
#include <stdio.h>
#include <typeinfo>
using namespace std;

class _Test_5 {
    public:
    _Test_5(){}
    void print(){
        cout<<"Test print : "<<typeid(*this).name()<<"pointertype : "<<typeid(this).name()<<endl;
    }
};

int main(int argc, char const *argv[])
{

    string test;
    cout<<typeid(test).name()<<endl;

    decltype(test) name = "Renzo";

    cout<<name<<endl;

    _Test_5 mytest;

    cout<<typeid(mytest).name()<<endl;
    
    decltype(mytest) thisis ;
    thisis.print();
    return 0;
}
