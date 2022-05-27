#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


void Test(int value){
    cout<<"The value is : "<<value<<endl;
}

bool NumberHigherX(int number, int max){
    return number>max;
}

int CountIf(vector<int> vec,bool (*func)(int,int),int max){
    int counter=0;
    for(int i=0;i<vec.size();i++){
        if(func(vec.at(i),max))
            counter++;
            
    }
    return counter;
}

int main(int argc, char const *argv[])
{

    Test(3);

    void (*pTest) (int) = Test;

    pTest(6);



    cout<<"-----------------"<<endl;

    vector<int> numbers;
    numbers.push_back(4);
    numbers.push_back(437);
    numbers.push_back(267);
    numbers.push_back(93);
    numbers.push_back(46);
    numbers.push_back(51);

    cout<<"Result : "<<CountIf(numbers,NumberHigherX, 50)<<endl;


    return 0;
}
