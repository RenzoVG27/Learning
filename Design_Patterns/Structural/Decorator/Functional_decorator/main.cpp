#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <functional>
#include <typeinfo>
using namespace std;

//This pattern is used to add funtionality to an object without modifying it (Closed open principle)


struct Logger
{
    function<void()> func;
    string funcname;

    Logger(const function<void()> &func, const string &funcname): func(func),funcname(funcname){}


    void operator()(){
        cout<<"Entering "<<funcname<<endl;
        func();
        cout<<"Exiting "<<funcname<<endl;
    }

};

template<typename Func>
struct Logger2
{
    Func func;
    string funcname;

    Logger2(const Func &func, const string &funcname): func(func),funcname(funcname){}


    void operator()(){
        cout<<"Entering "<<funcname<<endl;
        func();
        cout<<"Exiting "<<funcname<<endl;
    }

};

// typename can be infer only in function templates  but only when the template parameters can be inferred

template <typename Func> auto make_logger2(Func func, const string &name){
    return Logger2<Func>(func,name);
}

template<typename>struct Logger3;//this is required to use an speciaized template

template <typename R, typename ...Args>
struct Logger3<R(Args...)>{ // this is the specialized template of Logger3
    function<R(Args...)> func;
    string  name;

    Logger3(const function<R(Args...)> &func, const string &name):func(func),name(name){}

    R operator()(Args ...args){
        cout<<"Entering "<<name<<endl;
        R result = func(args...);
        cout<<"Exiting "<<name<<endl;
        return result;
    }

};


template <typename R, typename ...Args> 
auto make_logger3(R (*func)(Args...), string name){
    return  Logger3<R(Args...)>(func,name);
}

double add (double a, double b)
{
    cout<<a<<" + "<<b<<" = "<<(a+b)<<endl;
    return a+b;
}


struct Flower
{
  virtual string str() = 0;
};

struct Rose : Flower
{
  string str() override {
    return "A rose";
  }
};

struct RedFlower : Flower
{
    Flower &rose;
    RedFlower(Flower &rose):rose(rose){}
    
    string str() override {
        if(typeid(Rose) == typeid(rose))
            return rose.str() + " that is red";
        else{
            RedFlower *d = dynamic_cast<RedFlower*>(&rose);
            if(d!=nullptr)
                return rose.str();
            else
                return rose.str() + " and red";
        }
    }
};

struct BlueFlower : Flower
{
    Flower &rose;
    BlueFlower(Flower &rose):rose(rose){}
    
    string str() override {

        if(typeid(Rose) == typeid(rose))
            return rose.str() + " that is blue";
        else{
            BlueFlower *d = dynamic_cast<BlueFlower*>(&rose);
            if(d!=nullptr)
                return rose.str();
            else
                return rose.str() + " and blue";
        }
    }
};

int main(){

   Logger([](){cout<<"Hello world"<<endl;},"HElloFunction")();

    Logger2<function<void()>>([](){cout<<"Hello world"<<endl;},"HElloFunction")();

    auto log = make_logger2([](){cout<<"Hello world"<<endl;},"HElloFunction" );
    log();

    auto log2 = make_logger3(add,"Add");
    auto res = log2(10,12);
    cout<<"Result is "<<res<<endl;

    Rose rose;
    RedFlower red_rose{rose};
    RedFlower red_red_rose{red_rose};
    BlueFlower blue_red_rose{red_rose};
    RedFlower red_blue_red_rose{blue_red_rose};

    Flower &test = red_rose;

    cout<<rose.str()<<endl;
    cout<<red_rose.str()<<endl;
    cout<<red_red_rose.str()<<endl;
    cout<<blue_red_rose.str()<<endl;
    cout<<red_blue_red_rose.str()<<endl;


    cout<<is_base_of<Flower,decltype(test)>::value<<endl;
    cout<<"*************"<<endl;

    cout<<typeid(red_rose).name()<<endl;
    cout<<typeid(test).name()<<endl;


    cout<<is_same<decltype(red_rose),std::remove_reference<decltype(test)>::type>::value<<endl;

    return 0;
}