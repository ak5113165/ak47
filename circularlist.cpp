#include<iostream>
#include<stdlib.h>
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
  ~Node()
  {
      delete next;
  }
};
void insert(Node**head,int data)
{
    if(*head==NULL)
    {
        Node*newnode=new Node(data);
    *head=newnode;
    newnode->next=*head;
    }
    else
    {
    Node*newnode=new Node(data);
    newnode->next=(*head)->next;
    (*head)->next=newnode;
    }
}
void insertafter(Node**head,int data,int k)
{
    if(*head==NULL)
    {
        return ;
    }
    Node*temp=(*head)->next;
    Node*prev=NULL;
    while(temp!=*head&&k--)
    {
        prev=temp;
        temp=temp->next;
    }
    Node*newnode=new Node(data);
    prev->next=newnode;
    newnode->next=temp;
}
void insertend(Node**head,int data)
{
    if(*head==NULL)
    {
        return ;
    }
    Node*newnode=new Node(data);
    newnode->next=(*head)->next;
    (*head)->next=newnode;
    *head=newnode;
}
void print(Node*head)
{
    Node*p=head->next;
    if(head==NULL)
    {
        return ;
    }
    do
    {
        cout<<p->data<<"->";
        p=p->next;
    } while (p!=head->next);
    
}
int main()
{
    Node*head=NULL;
    insert(&head,2);
    insert(&head,3);
    insert(&head,5);
    insert(&head,7);
    insert(&head,9);
    insertend(&head,1);
    insertafter(&head,68,1);
    print(head);
    return 0;
}