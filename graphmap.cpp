#include<bits/stdc++.h>
using namespace std;
class graph
{
    unordered_map<string,list<pair<string,int>>> m;
    public:
    void addedge(string x,string y,bool bidr,int wt)
    {
       m[x].push_back(make_pair(y,wt));
       if(bidr)
       {
           m[y].push_back(make_pair(x,wt));
       }
    }
    void print()
    {
        for(auto p:m)
        {
            string city=p.first;
            list<pair<string,int>> nbr=p.second;
            cout<<city<<"->";
            for(auto x:nbr)
            {
                string dest=x.first;
                int dist=x.second;
                cout<<"("<<dest<<","<<dist<<")"<<",";
            }
            cout<<endl;
        }
    }
    void dijkstra(string src)
    {
        unordered_map<string,string>parent;
        unordered_map<string,int> dist;
        for(auto j:m)
        {
            parent[j.first]=-1;
            dist[j.first]=INT_MAX;
        }
        set<pair<int,string>> s;
        dist[src]=0;
        s.insert(make_pair(dist[src],src));
        while(!s.empty())
        {
         auto p=*(s.begin());
         string Node=p.second;
         int distance=p.first;
         s.erase(s.begin());
         for(auto nbr:m[Node])
         {
             if(distance+nbr.second<dist[nbr.first])
             {
                 string dest=nbr.first;
                 auto f=s.find(make_pair(dist[dest],dest));
                 if(f!=s.end())
                 {
                     s.erase(f);
                     
                 }
                 dist[dest]=distance+nbr.second;
                     s.insert(make_pair(dist[dest],dest));
                     parent[nbr.first]=Node;
             }
         }
        }
        for(auto i:dist)
        {
            cout<<i.first<<" IS LOCATED AT DISTANCE OF"<< i.second;
            cout<<endl;
        }
      
    }
    
};
int main()
{
    graph g;
    g.addedge("A","B",true,20);
    g.addedge("A","C",true,30);
    g.addedge("B","D",true,30);
    g.addedge("D","C",true,40);
    g.addedge("A","D",false,50);
    g.print();
    cout<<endl;
    g.dijkstra("A");
    return 0;
}

