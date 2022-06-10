#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main(){

    string parra = "Hello";

    cout<<"<p>"<<parra<<"</p>"<<endl;

    ostringstream ss;
    string lists[] = {"this","is","ugly"};

    ss<<"<ul>"<<endl;
    for(auto item:lists){
        ss<<"<li>"<<item<<"</li>"<<endl;
    }
    ss<<"</ul>"<<endl;

    cout<<ss.str()<<endl;



    return 0;
}