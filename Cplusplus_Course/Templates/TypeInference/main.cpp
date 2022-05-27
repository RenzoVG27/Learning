#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

template <typename T>
void Print(T a)
{
    cout<<"Template version: "<<a<<endl;
}

void Print(int a)
{
    cout<<"Non-Template version: "<<a<<endl;
}

template <typename T>
void Show()
{
    cout<<"2- Template version: "<<T()<<endl; //Default value (constructor)
}

int main(int argc, char const *argv[])
{


    Print(7); //non template
    Print<>(7) ; //template version

    Show<int>();//typename is mandatory in this function


    return 0;
}
