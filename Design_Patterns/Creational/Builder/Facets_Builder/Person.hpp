#pragma once

#include <string>
#include <ostream>

using namespace std;

class PersonBuilder;

class Person{
    //individual
    int age;
    string address;
    string name;

    //work
    string company, addressCompany;
    int salary{0};

    public:
    
    static PersonBuilder create();

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonLiveBuilder;

    friend std::ostream& operator<<(std::ostream& os, const Person& obj)
    {
        return os
        << "age: " << to_string(obj.age)
        << " address: " << obj.address
        << " name: " << obj.name
        << " company: " << obj.company
        << " addressCompany: " << obj.addressCompany
        << " salary: " << obj.salary;
    }

};