#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<map>
#include<queue>
using namespace std;
#define n 6
class graph
{
    vector<int>A[n];
    public:
    void addedge(int x,int y)
    {
        A[x].push_back(y);
        A[y].push_back(x);
    }
    void bfs(int x);
    void print()
    {
        for(int i=0;i<n;i++)
        {
            cout<<"vertex "<<i<<"->";
            for(auto it:A[i])
            {
                cout<<it<<",";
            }
            cout<<endl;
        }
    }
    void ankit(int x,map<int,bool>&m)
    {
        cout<<x<<" ";
        m[x]=true;
        for(int nbr:A[x])
        {
            if(!m[nbr])
            {
                ankit(nbr,m);
            }
        }
    }
    void dfs(int x)
    {
        map<int,bool>m;
        for(int i=0;i<n;i++)
        {
            for(auto p:A[i])
            {
                int Node=p;
                m[p]=false;
            }
        }
         ankit(x,m);
    }
    void dfsiterative(int x)
    {
       map<int,bool>m;
       stack<int>s;
       for(int i=0;i<n;i++)
        {
            m[i]=false;
        }
        s.push(x);
        while (!s.empty())
        {
            int Node=s.top();
            s.pop();
            if(!m[Node])
            {
                cout<<Node<<" ";
                m[Node]=true;
            }
            for(int nbr:A[Node])
            {
                if(!m[nbr])
                {
                    s.push(nbr);
                }
            }
        }
    }
};
void graph::bfs(int x)
    {
        map<int,bool>m;
        queue<int>q;
        q.push(x);
        m[x]=true;
        while(!q.empty())
        {
            int Node=q.front();
            q.pop();
            cout<<Node<<" ";
            for(int nbr:A[Node])
            {
                if(!m[nbr])
                {
                    q.push(nbr);
                    m[nbr]=true;
                }
            }
        }
    }
int main()
{
    graph g;
    g.addedge(0,1);
    g.addedge(0,3);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(4,5);
    cout<<endl;
    g.print();
    cout<<endl;
    g.dfs(0); 
    cout<<endl;
    g.bfs(0);
    cout<<endl;
    g.dfsiterative(0);
    
    return 0;
}