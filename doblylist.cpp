#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
    public:
         int data;
         Node*next;
         Node*prev;
         Node(int data)
        {
         this->data=data;
         prev=next=NULL;
        }
};
void insert(Node**head,int data)
{
    if(*head==NULL)
    {
        Node*temp=new Node(data);
        *head=temp;
        (*head)->next=NULL;
        (*head)->prev=NULL;
    }
    else
    {
    Node*temp=new Node(data);
    (*head)->prev=temp;
     temp->next=*head;
    *head=temp;
    }
}
void insertafter(Node**head ,int data,int k)
{
    if(head==NULL)
    {
        return ;
    }Node*newnode=new Node(data);
    Node*temp=*head;
    while(temp!=NULL&&k--)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
    
}
void insertend(Node**head,int data)
{
    if(head==NULL)
    {
        return ;
    }
    Node*newnode=new Node(data);
    Node*temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode->prev=temp;
    temp->next=newnode;
}
void print(Node*head)
{
    if(head==NULL)
    {
        return ;
    }
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}
void deleteet(Node**head,int key)
{
    if(*head==NULL)
    {
        return ;
    }
    Node*temp=*head;
    if(temp->data==key)
    {
        *head=temp->next;
        (*head)->prev=NULL;
    }
    Node*p=NULL;
    while(temp!=NULL)
    {
       if(temp->data==key)
       {
         p->next=temp->next;
         temp->prev=p;
       }
       p=temp;
       temp=temp->next;
    }
}
void reverse(Node**head)
{
    Node*curr=*head;
    if(curr==NULL||curr->next==NULL)
    {
        return ;
    }
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    *head=curr;
    curr->next=curr->prev;
    curr->prev=NULL;
    curr=curr->next;
    while(curr->prev!=NULL)
    {
        Node*temp=curr->next;
        curr->next=curr->prev;
        curr->prev=temp;
        curr=curr->next;
    }
    curr->prev=curr->next;
    curr->next=NULL;
}
int main()
{
    Node*head=NULL;
    insert(&head,1);
    insert(&head,21);
    insert(&head,11);
    insert(&head,19);
    insert(&head,91);
    insertafter(&head,54,3);
    insertend(&head,90);
    //deleteet(&head,1);
   // reverse(&head);
    print(head);
    return 0;
}