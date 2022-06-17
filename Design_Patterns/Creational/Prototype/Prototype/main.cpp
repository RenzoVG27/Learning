#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <memory>

using namespace std;

struct Address{
    int suite;
    string street;
    string city;

    Address(const int& suite, const string& street, const string& city):
    suite(suite),street(street),city(city){

    }

    Address(const Address& other):suite(other.suite),street(other.street),city(other.city){
        
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

    Contact(const Contact& other){
        name = other.name;
        address = new Address(*other.address);
    }

    friend ostream& operator<< (ostream &out, const Contact& other){
        return out<<"Contact: "<<other.name<<", "<<*other.address;
    }
};

struct ContactFactory{

    static unique_ptr<Contact> make(const string & name, const int& suite){
        static Contact main{"",new Address{0,"Las Gaviotas","Surco"}};

        return Create_Contact_From(name,suite,main);
    }

    private:

    static unique_ptr<Contact> Create_Contact_From(const string& name, const int& suite, const Contact& prototype){
        auto pt = make_unique<Contact>(prototype);
        pt->name = name;
        pt->address->suite = suite;
        return pt;
    }
};


int main(){

    /*Contact renzo{"Renzo Villacorta",new Address{27,"Las Gaviotas","Surco"}};
    Contact marcia{"Marcia Mancilla",new Address{28,"Las Gaviotas","Surco"}};
    Contact cayetano = renzo; //this copy the same address of Address;
    cayetano.name = "Cayetano Villacorta";
    cayetano.address->suite = 29;

    cout<<renzo<<endl;
    cout<<marcia<<endl;
    cout<<cayetano<<endl;*/


    auto mycontact = ContactFactory::make("Roberto Villacorta", 1260);
    cout<<*mycontact<<endl;



    return 0;
}