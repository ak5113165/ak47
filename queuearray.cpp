#include <bits/stdc++.h>
using namespace std;
#define s 5
void display(int a[], int front, int rear);
void push(int a[], int item, int &front, int &rear);
void pop(int a[], int &front, int &rear)
{
    if (front == rear)
    {
        cout << "queue is empty()";
    }
    cout<<endl;
    cout << a[front];
    front++;
}

int main()
{
    int a[s], item;
    int front = -1;
    int rear = -1;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        cout << " plz enter the elemennts store in queue";
        cin >> item;
        push(a, item, front, rear);
        display(a, front, rear);
        cout << "\n do u want to add more elements in quueu";
        cin >> ch;
    }
    int ok=1;
    while (ok == 1)
    {
        pop(a, front, rear);
        cout << endl;
        display(a, front, rear);
        cout<<endl;
        cout<<"u want to delete more element";
        cin>>ch;
        if(ch=='y'||ch=='Y')
        {
            ok==1;
        }
        else
        {
            ok=0;
        }
    }
}
void push(int a[], int item, int &front, int &rear)
{
    if (rear == s - 1)
    {
        cout << "\n queue is full";
    }
    if (front == -1)
        front = 0;
    rear++;
    a[rear] = item;
}
void display(int a[], int front, int rear)
{
    if (front == rear)
    {
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        cout << a[i] << " ";
    }
}
