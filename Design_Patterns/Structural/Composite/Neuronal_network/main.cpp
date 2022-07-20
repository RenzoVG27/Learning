#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>

using namespace std;

//CRTP curious recursive template pattern

struct Neuronal;

template <typename self>
class Someneurons
{
    public:
    template <typename T>
    void connect_to(T& other){
        for(Neuronal& from : *static_cast<self*>(this)){
            for(Neuronal& to : other){
                from.out.push_back(&to);
                to.in.push_back(&from);
            }
        }
    }

};

struct Neuronal:Someneurons<Neuronal>{
    vector<Neuronal*> in, out;
    int id;

    Neuronal(){
        static int id{1};
        this->id = id++;
    }

    Neuronal* begin(){
        return this;
    }

    Neuronal* end(){
        return this + 1;
    }

    friend ostream& operator<<(ostream &out, const Neuronal& other)
    {
        out<<"Neuronal network : "<< other.id<<endl;
        for(auto inItem: other.in){
            out<<"["<<inItem->id<<"]\t-->\t"<<other.id<<endl;
        }
        for(auto outItem: other.out){
            out<<"\t\t"<<other.id<<"\t-->\t["<<outItem->id<<"]"<<endl;
        }

        out<<"******************************"<<endl;
        return out;
    }

};

struct NeuronalLayer : vector<Neuronal>, Someneurons<NeuronalLayer>
{

    NeuronalLayer(int a){
        while(a-->0)
            emplace_back(Neuronal{});
    }

    friend ostream& operator<<(ostream &out, const NeuronalLayer& other){
        for(auto &a:other){
            out<<a<<endl;
        }
        return out;
    }



};



int main(){

    Neuronal n1,n2,n3;

    n1.connect_to(n2);
    n2.connect_to(n3);
    n3.connect_to(n1);

    cout<<n1<<n2<<n3<<endl;


    NeuronalLayer layer1{2}, layer2{3};

    n1.connect_to(layer1);
    layer2.connect_to(n2);
    layer1.connect_to(layer2);

    cout<<"____________________"<<endl;

    cout<<layer1<<endl;

    return 0;
}