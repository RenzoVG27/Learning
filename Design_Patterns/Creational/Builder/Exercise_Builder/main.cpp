#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#include "CodeBuilder.hpp"

int main(){

    auto cb = CodeBuilder("Person").add_field("name","string").add_field("age","int");
    cout<<cb<<endl;

    return 0;
}