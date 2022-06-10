#ifndef HTML_BUILDER_H
#define HTML_BUILDER_H


#include <string>
#include <vector>

struct  HtmlElement;

using namespace std;

struct HtmlBuilder{
    HtmlElement roots;
    HtmlBuilder(const string& name);

    string str();

    HtmlBuilder& add_child(const string &name, const string& value);
};


#endif