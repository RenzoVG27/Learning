#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void PrintVectorMeassures(vector <int> &numbers)
{
    cout<<"Size: "<<numbers.size()<<", Capacity: "<<numbers.capacity()<<endl;
}

int main(int argc, char const *argv[])
{
   
   vector <int> mylist;
   int capacity = mylist.capacity();

   PrintVectorMeassures(mylist);

   for(int i=0;i<50;i++)
   {

       mylist.push_back(i);
       //cout<<"--capacity : ---"<<capacity<<endl;
       //PrintVectorMeassures(mylist);
       
       if(capacity!=mylist.capacity())
       {
           capacity = mylist.capacity();
           cout<<"changed!!!"<<endl;
            PrintVectorMeassures(mylist);
       }
       //cout<<"-----"<<endl;
   }

   //PrintVectorMeassures(mylist);

   mylist.reserve(100);
   PrintVectorMeassures(mylist);

    return 0;
}
