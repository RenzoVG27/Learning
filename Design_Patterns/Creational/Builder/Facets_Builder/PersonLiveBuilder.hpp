#pragma once

#include "PersonBuilder.hpp"

class PersonLiveBuilder:public PersonBuilderBase{

    typedef PersonLiveBuilder Self;

    public:
    PersonLiveBuilder(Person &person):PersonBuilderBase(person){

    }
    
    Self& at(string address){
        per.address = address;
        return *this;
    }

    Self& name(string name){
        per.name = name;
        return *this;
    }

    Self& age(int age){
        per.age = age;
        return *this;
    }

    
};