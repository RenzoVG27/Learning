#include <iostream>
#include <string>
#include <tuple>
#include <vector>


enum class Relationship{
    parent,
    child,
    sibling
};

struct Person{
    std::string name;
};

struct RelationshipBrowser {
    virtual std::vector<Person> findAllTheChildsOf(const std::string &name) = 0;
};

struct Relationships: RelationshipBrowser{ // Low level because it is manipulatin the data directly, dtat storage and monipulation
    std::vector<std::tuple<Person,Relationship,Person>> relations;

    void add_parent_child(const Person &parent, const Person& child){
        relations.push_back({parent,Relationship::parent,child});
        relations.push_back({child,Relationship::child,parent});
    }

    std::vector<Person> findAllTheChildsOf(const std::string &name) {
        std::vector<Person> result;
        for(auto && [first,rel,second]: relations){
            if(first.name == name && rel == Relationship::parent){
                result.push_back(second);
            }
        }
        return result;
    }
};



struct RelationSearch{ //high level because it is a tool to researh data

//This implementations breaks this prinicple because high level module dependes on low level module and also dependes of the details of the implementation
//this should be fixed by adding an interface between this class and Reletipnships, also the implmentation of the search should be inserted into the reletionships class
    RelationSearch(RelationshipBrowser &relations){
        /*auto &Relations = relations.relations;
        for(auto && [first,rel,second]:Relations){
            if(first.name == "Jhon" && rel == Relationship::parent){
                std::cout<<"John has a child named "<<second.name<<std::endl;
            }

        }*/

        for(auto &person : relations.findAllTheChildsOf("Jhon")){
            std::cout<<"Jhon has a child called "<<person.name<<std::endl;
        }

    }
};


int main(){

    Person parent{"Jhon"};
    Person child1{"Juan"};
    Person child2{"Jose"};

    Relationships relas;
    relas.add_parent_child(parent,child1);
    relas.add_parent_child(parent,child2);

    RelationSearch relasearch(relas);

    return 0;
}