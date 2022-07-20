#include "Person.hpp"
#include <iostream>

using namespace std;

class Person::PersonImpl{
    public:
    void greet(Person *p);
};

Person::Person(const string& name):imp(new PersonImpl()),name(name){

}

Person::~Person(){
    delete imp;
}

void Person::greet(){
    imp->greet(this);
}

void Person::PersonImpl::greet(Person *p){
    cout<<"The name of the person is "<<p->name<<endl;
}