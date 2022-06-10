#include "HtmlBuilder.h"

using namespace std;


HtmlBuilder::HtmlBuilder(const string& name){
    roots.name = name;
}

string HtmlBuilder::str(){
    return roots.str();
}


HtmlBuilder& HtmlBuilder::add_child(const string &name, const string& value){
    HtmlElement element;
    element.name = name;
    element.value = value;

    roots.elements.push_back(element);

    return *this;
}