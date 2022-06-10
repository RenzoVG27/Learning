#pragma once
#include <string>
#include <ostream>

using namespace std;

class field{
    string name,type;
    public:
    field(const string& name, const string& type):name(name),type(type){}

    friend ostream & operator<<(ostream & os, const field& f){
        return os<<f.type<<"  "<<f.name<<";";
    }
};