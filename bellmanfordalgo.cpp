#include<iostream>
#include<stdio.h>
#include<vector>
#define n 3
using namespace std;
int main()
{
    int x;
    vector<vector<int>> v;
    for(int i=0;i<3;i++)
    {
        vector<int> temp;
        for(int j=0;j<n;j++)
        {  
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
   /* for(int i=0;i<5;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }*/
    vector<int>dist(3,INT_MAX);
    dist[0]=0;
    for(int i=0;i<3;i++)
    {
        bool a=true;
        for(auto nbr:v)
        {
            int u=nbr[0];
            int q=nbr[1];
            int w=nbr[2];
            if(dist[q]>dist[u]+w)
            {
                dist[q]=dist[u]+w;
                a=false;
            }
        }
        if(a)
        {
            break;
        }
    }
    for(int i=0;i<dist.size();i++)
    {
        cout<<dist[i]<<' ';
    }
    return 0;
}