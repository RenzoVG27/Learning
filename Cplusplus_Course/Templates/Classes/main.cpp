#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

template <class T>
class Test {
    private:
    T sum;

    public:
    Test(T a, T b){
        sum = a+b;
    }

    void Print(){
        cout<<"The result is : "<<sum<<endl;
    }

};

int main(int argc, char const *argv[])
{


    Test<int> mytest (10,12);
    mytest.Print();


    return 0;
}
