#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void insertpos(Node **head, int n, int data)
{
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL && n--)
    {
        prev = temp;
        temp = temp->next;
    }
    Node *newnode = new Node(data);
    prev->next = newnode;
    newnode->next = temp;
}
void insertend(Node **head, int data)
{
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newnode = new Node(data);
    temp->next = newnode;
    newnode->next = NULL;
}
void insert(Node **head, int data)
{
    /* if(*head==NULL)
    {
        Node*temp=new Node(data);
        temp->next=*head;
        *head=temp;
    }*/
    Node *newnode = new Node(data);
    newnode->next = *head;
    *head = newnode;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
void deletenode(Node **head)
{
    Node *temp = *head;
    if (temp == NULL)
    {
        cout << "list is empty";
    }
    *head = temp->next;
    delete temp;
}
void deletepos(Node **head, int n)
{
    Node *prev = NULL;
    Node *temp = *head;
    while (temp != NULL && n--)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
}
void deletend(Node **head)
{
    Node *temp = *head;
    Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
}
void reverse(Node **head)
{
    Node *next = NULL;
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    *head = prev;
}
void ankit(Node **head, Node **temp, int a, int b)
{
    Node *prev = *temp;
    while ((prev->next) != NULL)
    {
        prev = prev->next;
    }
    Node *curr = *head;
    Node *p = *head;
    for (int i = 0; i < b - 1; i++)
    {
        curr = curr->next;
    }
    prev->next = curr->next;
    for (int i = 0; i < a - 1; i++)
    {
        p = p->next;
    }
    p->next = *temp;
}
void sahil(Node **head, int a, int b)
{
    Node *p = *head;
    Node *q = *head;
    for (int i = 0; i < a; i++)
    {
        p = p->next;
    }
    for (int i = 0; i < b; i++)
    {
        q = q->next;
    }
    Node *next = NULL;
    Node *prev = NULL;
    Node *curr = p;
    int k = (b - a) + 1;
    while (curr != NULL && k--)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}
int main()
{
    Node *head = NULL;
    Node *temp = NULL;
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    print(head);
    cout << endl;
    sahil(&head, 2, 4);
    print(head);
    /*insert(&temp,11);
    insert(&temp,41);
    insert(&temp,91);
    insertend(&temp,31);
    insertpos(&temp,1,85);
    print(temp);
    cout<<endl;
    ankit(&head,&temp,2,3);
    print(head);*/
    return 0;
}
