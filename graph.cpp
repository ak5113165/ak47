#include<bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    list<int>*l;
    public:
    graph(int v)
    {
        this->v=v;

        l=new list<int>[v];

    }
    void addedge(int x,int y,bool bidr)
    {
        l[x].push_back(y);
        if(bidr)
        {
        l[y].push_back(x);
        }
    }
    void print()
    {
        for(int i=0;i<v;i++)
        {
            cout<<"vertex "<<i<<"->";
            for(int nbr:l[i])
            {
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }
    void bfs(int x)
    {
        map<int,int>m;
        queue<int>q;
        q.push(x);
        m[x]=true;
        while(!q.empty())
        {
            int Node=q.front();
            q.pop();
            cout<<Node<<" ";
            for(int nbr:l[Node])
            {
                if(!m[nbr])
                {
                    q.push(nbr);
                    m[nbr]=true;
                }
            }
        }
    }
     void dfsiterative(int x)
    {
       map<int,bool>m;
       stack<int>s;
       for(int i=0;i<v;i++)
        {
            for(auto p:l[i])
            {
                int Node=p;
                m[p]=false;
            }
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
            for(int nbr:l[Node])
            {
                if(!m[nbr])
                {
                    s.push(nbr);
                }
            }
        }
    }
    void ankit(int x,map<int,bool>&m)
    {
         cout<<x<<" ";
        m[x]=true;
        for(int nbr:l[x])
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
        for(int i=0;i<v;i++)
        {
            for(int p:l[i])
            {
                m[p]=false;
            }
        }
        
        ankit(x,m);
    }
    //CYCLE DETECTION IN UNDIRECTED GRAPHS BFS AND DFS;
    bool cyclehelper(int Node,map<int,bool>&m,int parent)
    {
        m[Node]=true;
        for(auto nbr:l[Node])
        {
           if(!m[nbr])
           {
             bool cyclemila=cyclehelper(nbr,m,Node);
             if(cyclemila==true)
             {
                 return true;
             }
           }
           else if(nbr!=parent)
           {
               return true;
           }
        }
        return false;
    }
    bool cycleund()
    {
        map<int,bool>m;
        for(int i=0;i<v;i++)
        {
            for(int p:l[i])
            {
                m[p]=false;
            }
        }
       return cyclehelper(0,m,-1);
    }
    bool sahil(int x,map<int,bool>&m)
    {
        queue<int>q;
        m[x]=true;
        q.push(x);
        int parent=0;
        while(!q.empty())
        {
            int Node=q.front();
            q.pop();
            for(auto nbr:l[Node])
            {
                if(!m[nbr])
                {
                    q.push(nbr);
                    m[nbr]=true;
                    parent=Node;
                }
                else if(parent!=nbr)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool bfscycle(int x)
    {
        map<int,bool>m;
        for(int i=0;i<v;i++)
        {
            for(auto p:l[i])
            {
                m[p]=false;
            }
        }
        for(int i=0;i<v;i++)
        {
            if(!m[i]&&sahil(i,m)==true)
            {
                return true;
            }
        }
        return false;
    }
    //CYCLE DETECTION IN DIRECTED GRAPH DFS;
    bool helper(int x,map<int,bool>&m1,map<int,bool>&m2)
    {
        m1[x]=true;
        m2[x]=true;
        for(auto nbr:l[x])
        {
            if(!m1[nbr])
            {
                bool c=helper(nbr,m1,m2);
                if(c==true)
                {
                    return true;
                }
            }
            else if(m2[nbr]==true)
            {
                return true;
            }
        }
        m2[x]=false;
        return false;
    }
    bool directcycle(int x)
    {
        map<int,bool>m1;
        map<int,bool>m2;
        for(int i=0;i<v;i++)
        {
            for(auto p:l[i])
            {
                m1[p]=false;
                m2[p]=false;
            }
        }
        return helper(x,m1,m2);
    }
};
int main()
{
    graph g(5);
    g.addedge(0,1,false);
    g.addedge(1,2,false);
    g.addedge(2,3,false);
    g.addedge(3,4,false);
    g.addedge(4,0,false);
    g.print();
    cout<<endl;
    g.bfs(0);
    cout<<endl;
    g.dfs(0);
    cout<<endl;
    g.dfsiterative(0);
    cout<<endl;
    if(g.cycleund())
    {
        cout<<"yes graph contain a cycle";
    }
    else 
        cout<<"No graph does not contain a cycle";
        cout<<endl;
        if(g.bfscycle(0))
        {
            cout<<"yes graph contain a cycle";
        }
        else
        cout<<"No graph does not contain a cycle";
        cout<<endl;
        if(g.directcycle(0))
        {
            cout<<"yes graph contain a cycle";
        }
        else
        cout<<"No graph does not contain a cycle";

    return 0;

}