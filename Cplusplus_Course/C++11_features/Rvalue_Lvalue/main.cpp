#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;


class Test{
    static const int size_array = 100;
    public:
    int *vector;

    Test(){
        vector = new int[size_array]{};
        cout<<"Constructor"<<endl;
    }
    ~Test(){
        cout<<"Destructor"<<endl;
        delete []vector;
    }

    Test (const Test& other):Test{}{
        cout<<"Copy constructor"<<endl; 
        memcpy(vector, other.vector,size_array*sizeof(int));

    }

    Test(Test &&other):vector(other.vector){
        cout<<"Move Constructor"<<endl;
        other.vector = nullptr;
    }

    const Test& operator=(const Test& other){
        cout<<"Assignament operator"<<endl;
        memcpy(vector, other.vector,size_array*sizeof(int));
        return *this;
    }

    Test& operator=(Test &&other){
        cout<<"Assignament operator but from rvalue reference"<<endl;
        delete [] vector;
        vector = other.vector;
        other.vector = nullptr;
        return *this;
    }

};

ostream &operator<<(ostream &out, Test &other){
    out<<"Hola print"<<flush;
    return out;
}

Test getTest(){
    return Test();
}


int main(int argc, char const *argv[])
{
    Test test1;

    test1 = Test();

    vector<Test> vec;
    vec.push_back(Test());

    return 0;
}
