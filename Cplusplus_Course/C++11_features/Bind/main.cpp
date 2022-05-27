#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <functional>
using namespace std;
using namespace placeholders;


int adding(int a, int b, int c){
    cout<<"Sum of: "<<a<<"+"<<b<<"+"<<c<<endl;
    return a+b+c;
}

void RunFunc(function<int(int,int)> func,int a, int b){
    cout<<"Runfunc: "<<func(a,b)<<endl;
}

class Test {
    public:
    void PrintResult(int a, int b){
        cout<<"Result: "<<a+b<<endl;
    }

    static int calculateCube(int a){
        return a*a*a;
    }

};


int main(int argc, char const *argv[])
{

    cout<<"result:"<<adding(10,20,30)<<endl;

//bind function with arguments
    auto newbind = bind(adding,_1,_2,15);
    newbind(12,13);
    newbind(11,10);

//adapting func pointer
    RunFunc(newbind,50,60);

    Test test1;
//using bind with a class
    auto otherBind = bind(&Test::PrintResult,test1,17,18);
    otherBind();
//using static  member function;
    auto staticBind = bind(&Test::calculateCube,_1);
    cout<<"Result static: "<<staticBind(12)<<endl;
    
    return 0;
}
