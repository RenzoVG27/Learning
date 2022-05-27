#include <iostream>
#include <stdio.h>
#include "ring.h"
using namespace std;

int main(int argc, char const *argv[])
{
    
    ring<string> myring(3);
    myring.add("one");
    myring.add("two");
    myring.add("three");
    myring.add("four");
    myring.add("five");
    

    for(int i=0;i<myring.size();i++){
        cout<<myring.get(i)<<endl;
    }

    cout<<"****C98 style*******"<<endl;

    for ( ring<string>::iterator it = myring.begin(); it!=myring.end();it++){
        cout<<*it<<endl;
    }

    cout<<"*****c11 style*******"<<endl;


    for(auto test:myring){
        cout<<test<<endl;
    }




    return 0;
}
