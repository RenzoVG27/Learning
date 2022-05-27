#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

template <typename T>
void Print(T a)
{
    float m = a/2;
    cout<<m<<endl;
}

int main(int argc, char const *argv[])
{


    Print<float>(7);//If you dont especify the value, the result can be different 3.5
    Print(7);//3


    return 0;
}
