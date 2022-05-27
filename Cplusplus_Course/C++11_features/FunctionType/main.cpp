#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

const int size_total = 3;

bool check(string &test){
    return test.size() == size_total;
}

class CheckClass{
    public:
    bool operator()(const string &test){
        return test.size()==size_total;
    }
};

int countIf_new(vector<string>::iterator itb, vector<string>::iterator ite, function<bool(string&)> test){
    int counter{0};
    for(decltype(itb) itera = itb; itera!=ite;itera++){
        if(test(*itera)){
            counter++;
        }
    }
    return counter;
}

void run(function<int(int,int)> test){
    cout<<"The result is: "<<test(10,50)<<endl;
}


int main(int argc, char const *argv[])
{
    
    vector<string> numbers{"one","two","Three","Four"};


    auto lambda = [](string &test){ 
        return test.size() == size_total;
        };
    //lambda call
    cout<<count_if(numbers.begin(),numbers.end(),lambda)<<endl;

    //function call
    cout<<count_if(numbers.begin(),numbers.end(),check)<<endl;

    //functor call
    CheckClass test;
    cout<<count_if(numbers.begin(),numbers.end(),test)<<endl;


    function<int(int,int)> lamd = [](int a, int b){return a*b;};

    run(lamd);

    cout<<"Result of the new counif: "<<countIf_new(numbers.begin(),numbers.end(),test)<<endl;


    return 0;
}
