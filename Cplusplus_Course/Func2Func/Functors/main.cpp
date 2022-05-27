#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Test {
    public:
    virtual bool operator()(string value)=0;
};


struct TestRenzo : public Test{
    bool operator()(string value){
        return value=="Renzo";
    }
};

struct TestMarcia : public Test{
    bool operator()(string value){
        return value=="Marcia";
    }
};

void check(string toevaluate, Test &test){
    if(test(toevaluate)){
        cout<<"Passed"<<endl;
    }
    else
    {
        cout<<"Not passed"<<endl;
    }
}

int main(int argc, char const *argv[])
{
    TestMarcia a;
    check("Marcia",a);
    check("Renzo",a);

    auto renzo = "Test";
    
    return 0;
}
