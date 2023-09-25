#include <bits/stdc++.h>
using namespace std;
void bfs(int x,vector<vector<int>>v)
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
            for(int nbr:v[Node])
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
    int n=5;
    vector<vector<int>> v(n);
    vector<vector<int>> vis(n);
    
    v[1].push_back(2);
    v[2].push_back(3);
    v[3].push_back(4);
    v[4].push_back(5);
    for(int i=1;i<n;i++)
    {
        cout<<i<<":";
       for(auto x:v[i])
       {
           cout<<"->"<<x<<" ";
       }   
       cout<<endl;
    }
    cout<<endl;
    bfs(1,v);
    return 0;
}