#pragma once


#include <string>

using namespace std;

class Person{
    private:
    string name;

    class PersonImpl;
    PersonImpl *imp;

    public: 
    Person(const string& name);
    ~Person();

    void greet();
};