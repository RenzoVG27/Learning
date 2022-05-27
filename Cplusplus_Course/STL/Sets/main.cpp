#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void PrintIterator(vector <pair<int,string> >::iterator it)
{
    cout<<"Key: "<<it->first<<", value: "<<it->second<<endl;
}

int main(int argc, char const *argv[])
{
   
   vector <pair<int,string> > mylist;

   mylist.push_back(make_pair(1,"Renzo Villacorta"));
   mylist.push_back(make_pair(2,"Marcia Villacorta"));
   mylist.push_back(make_pair(3,"Caye Villacorta"));
   mylist.push_back(make_pair(4,"Guille Villacorta"));

   vector <pair<int,string> >::iterator it = mylist.begin();

   PrintIterator(it);

   it++;

   it++;

   PrintIterator(it);

   it++;

   if(it == mylist.end()){
       cout<<"This isthe end"<<endl;
   }else{
       PrintIterator(it);
   }

   it++;

   if(it == mylist.end()){
       cout<<"Now This is the end"<<endl;
   }else{
       PrintIterator(it);
   }

    return 0;
}
