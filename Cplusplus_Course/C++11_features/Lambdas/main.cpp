#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;


class Test{
    private:
    string name{"Renzo"};
    int age{31};

    public:

    Test(){
        cout<<"Execute the constructor : "<<name<<endl;
    }
    virtual ~Test(){
        cout<<"Execute the destructor"<<endl;
    }

    string getName(){
        return name;
    }

    void setName(string newname){
        name = newname;
    }

    void run(){
        int childs{1};
        double heigh{1.69};


        auto pLambda = [&childs,this](){
            name = "Marcia";
            childs = 2;

            cout<<name<<", "<<age<<", "<<childs<<endl;
        };

        pLambda();

    }
};


void runCallback(double(*pFunc)(double,double)){
    auto result = pFunc(10.5,6.5);
    cout<<"The result: "<<result<<endl;
}

int main(int argc, char const *argv[])
{
    auto firstlambda = [](double dbd){cout<<"Hello lambda: "<<dbd<<endl;};

    firstlambda(5.5);//running lambda without input parameters


    auto secondlambda = [](double a, double b)->double{ //specify the return type when it is ambigou
        if(b==0)
        return 0;

        return a/b;
    };

    cout<<secondlambda(10,30)<<endl; //running lambda with input parameters

    runCallback(secondlambda);//using lambda as a function pointer

    runCallback([](double a,double b){return a+b;}); // using lamda directly




    cout<<"\n\n>>>>>>>>>>>Capturing in lambda>>>>>>>>>>>>>>\n"<<endl;

    int one=1,two=2,three=3;

    [one](){cout<<"Capture the one by value: "<<one<<endl;}();

    [=](){cout<<"Capture all by value: "<<two<<endl;}();
    //[=](){one = 5;cout<<"Capture all by value, cant change any variable inside: "<<two<<endl;}();

    [=,&three](){three=10,cout<<"Capture all by value, except three by reference: "<<three<<", "<<two<<endl;}();

    [&](){two = 50;cout<<"Capture all by reference: "<<two<<endl;}();

    [&,two](){three=15;cout<<"Capture all by reference except two that cant be changed: "<<three<<endl;}();

    cout<<"\n\n>>>>>>>>>>>Capturing this in Lambda>>>>>>>>>>>>>>\n"<<endl;

    Test mytest;
    mytest.run();


    cout<<"\n\n>>>>>>><>>>>>mutable keyword<<<<<<<<<<\n\n"<<endl;


    auto mutaLambda = [mytest]()mutable{ //mutable dont create a copy (dont execute the constructor nor destrcutor)
        mytest.setName("Cayetano");
        cout<<"New three : "<<mytest.getName()<<endl;
    };

    mutaLambda();

    cout<<"The old value : "<<mytest.getName()<<endl;


    return 0;
}
