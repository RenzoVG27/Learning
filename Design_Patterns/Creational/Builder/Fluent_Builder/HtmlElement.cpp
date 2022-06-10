
#include "HtmlElement.h"

using namespace std;

string HtmlElement::str(){
    ostringstream ss;
        ss<<"<"<<name<<">"<<endl;
        ss<<value<<endl;
        for(auto item:elements){
            ss<<item.str();
        }
        ss<<"</"<<name<<">"<<endl;
        return ss.str();
}

HtmlBuilder& HtmlElement::builder(string name){
    return {name};
}