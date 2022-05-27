#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Test {

    int a{5};
    string b{"renzo"};

    public:

    Test()=default;
    Test(const Test &other) = delete; //avoid copy the object by initialization/copy constructor
    Test &operator=(const Test& other) = delete; // avoid copy the object using the equal symbol

    Test(int a):a(a){

    }

    
    friend ostream &operator<<(ostream &out,Test &mytest);


    
};

ostream &operator<<(ostream &out,Test &mytest){
    out<<mytest.a<<", "<<mytest.b<<flush;
    return out;
}


int main(int argc, char const *argv[])
{

    Test mytest;
    cout<<mytest<<" - "<<endl;
   
    Test mytest2(20);
    cout<<mytest2<<endl;

/* remove copy constructor
    Test mytest3 = mytest2;
    cout<<mytest3<<endl;

//remove asignation symbol
    mytest3 = mytest;
    cout<<mytest3<<endl;

*/

    return 0;
}
