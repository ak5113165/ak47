#include<iostream>
#include<stdio.h>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
void pop(Node**front)
{
    Node*temp=*front;
  if(*front==NULL)
  {
      cout<<"sorry";
  }
  *front=(*front)->next;
  delete temp;
  
  
}
void insetup(Node**front,int data)
{
    Node*newnode=new Node(data);
    if(*front==NULL)
    {
        *front=newnode;
    }
    newnode->next=*front;
    *front=newnode;
}
void insert(Node**rear,Node**front,int data)
{
    Node*newnode=new Node(data);
    if(*front==NULL)
    {
        *front=*rear=newnode;
    }
    (*rear)->next=newnode;
    (*rear)=newnode;
}
void print(Node*front)
{
    if(front==NULL)
    {
        cout<<"sorry";
    }
    Node*temp=front;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ->";
        temp=temp->next;
    }
}
int main()
{
    Node*front=NULL;
    Node*rear=NULL;
    insert(&rear,&front,1);
     insert(&rear,&front,2);
      insert(&rear,&front,3);
       insert(&rear,&front,4);
        insert(&rear,&front,5);
        pop(&front);
        insetup(&front,1);
        print(front);
}