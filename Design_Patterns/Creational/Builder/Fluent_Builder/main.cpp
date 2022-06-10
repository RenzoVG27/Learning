#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "HtmlBuilder.h"

using namespace std;





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
    builder.add_child("li","hello").add_child("li","world");
    cout<<builder.str()<<endl;
    



    return 0;
}