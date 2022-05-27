#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int square (int x){
    return x*x;
}

int cube(int &m){//to accept rvalue we must change to const (const int &m)
    return m*m*m;
}


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


void check( const Test& value){
    cout<<"Left value reference function"<<endl;
}

void check(Test &&value){
    cout<<"Right value reference function"<<endl;
}


int main(int argc, char const *argv[])
{
    int value = 7;

    int *newval = &value;

    (*newval)++;

    cout<<newval<<", value: "<<value<<endl;

    int *pvalue = &++value;

    //int *pvalue1 = &value++; //unable to compile cuz this rvalue cant be addressed

    int result = square(10);
    //int result2 = &square(18);//output of functions are rvalue  and cnt be addressed(temporal)

    int m = 9;
    result = cube(m);
    //result = cube(10);//cant compile cuz cube function ask for a reference of a lvalue, not a rvalue;


//leftvalue reference, use const to reference a lvalue
    Test test1(getTest()); //the copy constructor has const in order to acept reference to lvalue

//rvalue reference, use double & to refer an rvalue;
    Test &&leftval = getTest();


    cout<<"add od rvalue ref: "<<&leftval<<", value : "<<leftval<<endl;


    check(Test());
    check(test1);

    return 0;
}
