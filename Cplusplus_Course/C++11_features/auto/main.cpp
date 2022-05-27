#include <iostream>
#include <stdio.h>
#include <typeinfo>
#include <string>
using namespace std;

auto Test() -> int{ 
    return 2;
}

template <class T,class U>
auto Test2(T first, U second) -> decltype(first + second){

    cout<<typeid(first).name()<<endl;
    return first + second;
}

int main(int argc, char const *argv[])
{
    auto name = "Renzo";
    cout<<"Type: "<<typeid(name).name()<<", Value: "<<name<<endl;

    auto age = 7.2;
    cout<<"Type: "<<typeid(age).name()<<", Value: "<<age<<endl;   

    cout<<"auto in function: "<<Test()<<endl;

    cout<<"auto in template func: "<<Test2(string("renzo"),string("marcia"))<<endl;

    return 0;
}
