#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Test{
    public:
    int a{10};

    Test(){
        cout<<"Constructor"<<endl;
    }
    ~Test(){
        cout<<"Destructor"<<endl;
    }

    Test (const Test& other){
        cout<<"Copy constructor"<<endl;
        a=other.a;
    }

    const Test& operator=(const Test& other){
        cout<<"Assignament operator"<<endl;
        a = other.a;
        return *this;
    }

};

ostream &operator<<(ostream &out, Test &other){
    out<<other.a<<flush;
    return out;
}

Test getTest(){
    return Test();
}


int main(int argc, char const *argv[])
{
    Test test1 = getTest();

    cout<<test1<<endl;

    //flag to disable elide optimization :  -fno-elide-constructors


    return 0;
}
