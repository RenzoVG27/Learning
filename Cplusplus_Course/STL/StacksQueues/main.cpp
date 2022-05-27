#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

void PrintIterator(vector <pair<int,string> >::iterator it)
{
    cout<<"Key: "<<it->first<<", value: "<<it->second<<endl;
}

int main(int argc, char const *argv[])
{
   
   queue <int> newqueue;//FIFO
   
   newqueue.push(30);
   newqueue.push(130);
   newqueue.push(40);
   newqueue.push(50);


    while(newqueue.size()!=0)
    {
        int a = newqueue.front();
        cout<<a<<endl;
        newqueue.pop();
    }


   cout<<"---------------"<<endl;


   //-----------------


   stack<float> newStack;//LIFO

   newStack.push(1.0);
   newStack.push(3.0);
   newStack.push(17.4);
   newStack.push(3.9);

   float b = newStack.top();

   cout<<b<<endl;

   newStack.pop();

   b = newStack.top();

   cout<<b<<endl;

    return 0;
}
