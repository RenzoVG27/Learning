#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

void PrintSet(set<int> &mySet)
{
    for(set<int>::iterator it = mySet.begin();it!=mySet.end();it++){
        cout<<*it<<endl;
    }
}

class Person{
    public :
    Person():age(0),name(""){

    }

    Person (int age,string name):age(age),name(name){

    }

    void Print() const{
        cout<<age<<": "<<name<<endl;
    }

    bool operator<(const Person &other) const{
        return name<other.name;
    }


    int age;
    string name;



};

void PrintSetPerson(set<Person> &myset){
    for(set<Person>::iterator it = myset.begin();it!=myset.end();it++){
        it->Print();
    }
}

int main(int argc, char const *argv[])
{
   
   
  
    return 0;
}
