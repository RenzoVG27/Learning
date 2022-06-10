
#ifndef HTML_ELEMENT_H
#define HTML_ELEMENT_H

#include <string>
#include <vector>
#include <sstream>

#include "HtmlBuilder.h"

using namespace std;

struct  HtmlBuilder;

struct HtmlElement{
    string name, value;
    vector <HtmlElement> elements;

    string str();

    static HtmlBuilder& builder(string name);
};


#endif