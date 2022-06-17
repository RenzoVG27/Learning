#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

struct Address{
    int suite;
    string street;
    string city;

    Address(const int& suite, const string& street, const string& city):
    suite(suite),street(street),city(city){

    }

    friend ostream& operator<< (ostream &out, const Address& other){
        return out<<"Address : "<<other.suite<<", "<<other.street<<", "<<other.city;
    }

};

struct Contact {
    string name;
    Address *address; //this will make us to implement a deep copy and requiry a prototype;

    Contact(const string& name, Address *address):name(name),address(address){

    }

    friend ostream& operator<< (ostream &out, const Contact& other){
        return out<<"Contact: "<<other.name<<", "<<*other.address;
    }
};


int main(){

    Contact renzo{"Renzo Villacorta",new Address{27,"Las Gaviotas","Surco"}};
    Contact marcia{"Marcia Mancilla",new Address{28,"Las Gaviotas","Surco"}};
    Contact cayetano = renzo; //this copy the same address of Address;
    cayetano.name = "Cayetano Villacorta";
    cayetano.address->suite = 29;

    cout<<renzo<<endl;
    cout<<marcia<<endl;
    cout<<cayetano<<endl;



    return 0;
}