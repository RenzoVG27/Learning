#include <iostream>
#include <stdio.h>
#include <map>
#include <unordered_map>

using namespace std;

class Employee
{
    public:

    Employee():id(""),age(0){

    }

    Employee(string id,int age): id(id),age(age)
    {

    }

    Employee (const Employee &emp){
        cout<<"!!!!Copy constructor"<<emp.age<<endl;
        id = emp.id;
        age = emp.age;
    }

    string id;
    int age;
};
template <typename T> //for unordered and ordered maps (map<string,Employee> or unordered_map<string,Employee>)
void PrintMap(T &mymap)
{
    cout<<"****************"<<endl;
    for(auto it = mymap.begin();it!=mymap.end();it++){
        cout<<"["<<it->first<<"] : "<<it->second.id<<", "<<it->second.age<<endl;
    }
    cout<<"****************"<<endl;
}

int main(int argc, char const *argv[])
{
   map<string,Employee> employees;
   employees["Renzo"] = Employee("1234",31);
   employees["Marcia"] = Employee("7777",32);
   employees["Caye"] = Employee("7777",2);


    employees.insert(make_pair("Guille",Employee("18181",6)));


    PrintMap(employees);


    return 0;
}
