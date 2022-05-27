#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;



int main(int argc, char const *argv[])
{
//c++ 98
    struct {
        int a ;
        string b;
        float c;
    } m1 = {2,"Hello",4.0};

    class test{
        
        public :
        int a;
        int b;

        void print(){cout <<a<<endl;}

        private:

    };
    
    cout<<m1.b<<endl;

    test mtest = {10,20}; // creates a default constructor with 2 arguments

    mtest.print();

    vector<int> myvector;
    myvector.push_back(5);
    myvector.push_back(3);
    myvector.push_back(50);

    cout<<myvector[2]<<endl;

    //INITIALIZATION C11

    int value{30};
    cout<<value<<endl;

    int *pInts{}; //pInts = nullptr
    cout<<pInts<<endl;

    float *pfloat = new float[3]{1.1,2.3,5.4};
    cout<<pfloat[2]<<endl;

    vector<string> myvec{"hola","como estas","ytu?"};
    cout<<myvec[2]<<endl;

    struct {
        int a;
        float b;
    }c1{3,4.5};

    cout<<c1.b<<endl;







    return 0;
}
