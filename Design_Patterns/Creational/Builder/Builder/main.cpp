#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


struct HtmlElement{
    string name, value;
    vector <HtmlElement> elements;

    string str(){
        ostringstream ss;
        ss<<"<"<<name<<">"<<endl;
        ss<<value<<endl;
        for(auto item:elements){
            ss<<item.str();
        }
        ss<<"</"<<name<<">"<<endl;
        return ss.str();
    }
};


struct HtmlBuilder{
    HtmlElement roots;
    HtmlBuilder(const string& name){
        roots.name = name;
    }

    string str(){
        return roots.str();
    }

    void add_child(const string &name, const string& value){
        HtmlElement element;
        element.name = name;
        element.value = value;

        roots.elements.push_back(element);
    }
};

int main(){

    /*string parra = "Hello";

    cout<<"<p>"<<parra<<"</p>"<<endl;

    ostringstream ss;
    string lists[] = {"this","is","ugly"};

    ss<<"<ul>"<<endl;
    for(auto item:lists){
        ss<<"<li>"<<item<<"</li>"<<endl;
    }
    ss<<"</ul>"<<endl;

    cout<<ss.str()<<endl;
    */

    HtmlBuilder builder ("ul");
    builder.add_child("li","hello");
    builder.add_child("li","world");
    cout<<builder.str()<<endl;
    



    return 0;
}