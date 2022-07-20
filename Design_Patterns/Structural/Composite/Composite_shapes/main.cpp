#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>

using namespace std;

struct Indent{
    int idt{0};
    Indent(int idt):idt(idt)
    {

    }

    friend ostream & operator<<(ostream &out, const Indent& idet){
        for(int i=0;i<idet.idt;i++)
            out<<"\t";
        return out;
    }

    friend const Indent operator+(const Indent& idt,int value){
        return Indent{idt.idt + value};
    }

};


struct HtmlObject{
    string name, value;

    HtmlObject(string name, string value):name{name},value{value}
    {}

 
    virtual void draw(int indent = 0) = 0;
    virtual void draw(const Indent& idet) = 0;

};

struct Parragraph: HtmlObject{
    Parragraph(const string& title):HtmlObject("p",title)
    {}

    void draw(int indent = 0) override{
        cout<<Indent(indent)<<"<"<<name<<">"<<value<<"</"<<name<<">"<<endl;
    }

    void draw(const Indent& idet) override{
        cout<<idet<<"<"<<name<<">"<<value<<"</"<<name<<">"<<endl;
    }
};

struct Group: HtmlObject{

    vector<HtmlObject*> objects;

    Group(const string& title):HtmlObject("",title)
    {}

    void draw(int indent = 0) override{
        
        cout <<Indent(indent)<<"<"<<value<<">"<<endl;
        for(auto item:objects)
            item->draw(indent+1);
        cout<<Indent(indent)<< "</"<<value<<">"<<endl;
    }

    void draw(const Indent& idet) override{
        
        cout <<idet<<"<"<<value<<">"<<endl;
        for(auto item:objects)
            item->draw(idet+1);
        cout<<idet<< "</"<<value<<">"<<endl;
    }
};

int main(){

    Parragraph p("renzo");
    Parragraph p2("Marcia");

    Group g1("group1");
    g1.objects.push_back(&p);

    Group g2("subgroup");
    g2.objects.push_back(&p2);

    g1.objects.push_back(&g2);

    g1.draw();


    return 0;
}