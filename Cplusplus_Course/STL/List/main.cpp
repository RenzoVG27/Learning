#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

void PrintList(list <int> mylist)
{
    cout<<"****************"<<endl;
    int cnt = 0;
    for(int ind:mylist){
        cnt++;
        cout<<"["<<cnt<<"]->"<<ind<<endl;
    }
    cout<<"****************"<<endl;
}

int main(int argc, char const *argv[])
{
   
   list <int> mylist;

   mylist.push_back(10);
   mylist.push_back(21);
    mylist.push_back(32);
    mylist.push_back(43);
    mylist.push_front(9);

    PrintList(mylist);

    list<int>::iterator it = mylist.begin();
    it++;
    it = mylist.erase(it);

    cout<<"new value: "<<*it<<endl;

    PrintList(mylist);

    


    return 0;
}
