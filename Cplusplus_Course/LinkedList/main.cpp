#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;


class Node{
    public:
    int data;
    Node *next=nullptr;
};

void PrintList(Node *n)
{
    cout<<"****************"<<endl;
    
    while(n!=nullptr){
        cout<<"value: "<<n->data<<endl;
        n=n->next;
    }

    cout<<"****************"<<endl;
}

void InsertNode(Node **head,int data)
{
    Node *n = new Node();
    n->data = data;
    n->next = *head;
    *head = n;
}

int main(int argc, char const *argv[])
{
   
   
   Node *first = new Node;
   first->data = 10;
   

   InsertNode(&first,50);

   PrintList(first);





    return 0;
}
