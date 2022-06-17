#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace std;
using namespace boost;

struct Address{
    int suite;
    string street;
    string city;

    Address(){}

    Address(const int& suite, const string& street, const string& city):
    suite(suite),street(street),city(city){

    }

    Address(const Address& other):suite(other.suite),street(other.street),city(other.city){
        
    }

    friend ostream& operator<< (ostream &out, const Address& other){
        return out<<"Address : "<<other.suite<<", "<<other.street<<", "<<other.city;
    }

    private :
    friend class boost::serialization::access;
    template <typename archive>
    void serialize(archive &ar, const unsigned version){
        ar & suite & street & city;
    }

};

struct Contact {
    string name;
    Address *address; //this will make us to implement a deep copy and requiry a prototype;

    Contact (){}
    Contact(const string& name, Address *address):name(name),address(address){

    }

    Contact(const Contact& other){
        name = other.name;
        address = new Address(*other.address);
    }

    friend ostream& operator<< (ostream &out, const Contact& other){
        return out<<"Contact: "<<other.name<<", "<<*other.address;
    }

    private :
    friend class boost::serialization::access;
    template <typename archive>
    void serialize(archive &ar, const unsigned version){
        ar & name & address;
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

    auto clone = [](Contact &other){
        ostringstream oss;
        boost::archive::text_oarchive oa(oss);
        oa<<other;
        cout << oss.str()<< endl;

        istringstream iss;
        boost::archive::text_iarchive ia(iss);
        Contact newone;
        ia >> newone;

        return newone;
    };

    Contact ross{"Rossana Garrido",new Address{56,"Los Cedros","Surco"}};
    Contact ross2 = clone(ross);

    cout<<ross2<<endl;

    return 0;
}