#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Test {
    public:


    Test(initializer_list<T> list){
        mylist=list;
    }

    void print(){
        for(T ind:mylist){
            cout<<ind<<endl;
        }
    }

    private:
    vector<T> mylist;
};


int main(int argc, char const *argv[])
{


    Test<string> myTest{"Renzo","Marcia","Cayetano","Guillermino"};
    myTest.print();




    return 0;
}
