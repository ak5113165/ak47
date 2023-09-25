#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
void deletemid(stack<int>&s,int n,int current)
{
    if(s.empty()==true||current==n)
    {
        return;
    }
    int x=s.top();
    s.pop();
    deletemid(s,n,current+1);
   if(current!=n/2)
   {
     s.push(x);
   }
}
stack<int> sort(stack<int>& s)
{
    stack<int> v;
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        while(!v.empty()&&v.top()>x)
        {
            s.push(v.top());
            v.pop();
        }
        v.push(x);
    }
    return v;
}
int main()
{
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(33);
    s.push(20);
    s.push(10);
    int current=0;
  /* deletemid(s,s.size(),current);
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        cout<<x<<" ";
    }*/
    stack<int> v=sort(s);
    while(!v.empty())
    {
    int x=v.top();
    v.pop();
    cout<<x<<" ";
    }
    
}