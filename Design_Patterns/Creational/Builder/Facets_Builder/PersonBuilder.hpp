#pragma once

#include "Person.hpp"

class PersonJobBuilder;
class PersonLiveBuilder;

class PersonBuilderBase{
    protected:
        Person &per;
    public:
        PersonBuilderBase(Person& p):per(p){}

        PersonJobBuilder work() const;
        PersonLiveBuilder lives() const;

        operator Person() {
            return std::move(per);
        }
};

class PersonBuilder: public PersonBuilderBase{
    Person p;

    public:
    PersonBuilder(): PersonBuilderBase{p}{}
};  