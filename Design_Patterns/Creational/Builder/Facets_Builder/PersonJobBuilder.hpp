#pragma once

#include "PersonBuilder.hpp"

class PersonJobBuilder:public PersonBuilderBase{

    typedef PersonJobBuilder Self;

    public:
    PersonJobBuilder(Person &person):PersonBuilderBase(person){

    }
    
    Self& at(string address){
        per.addressCompany = address;
        return *this;
    }

    Self& name(string name){
        per.company = name;
        return *this;
    }

    Self& earn(int anual){
        per.salary = anual;
        return *this;
    }

    
};