#include<iostream>
#include<vector>
using namespace std;
void ankit(vector<vector<int>>&v,vector<vector<int>>&vis,int sr,int sc,int n,int m,int oldcolor,int newcolor)
{
    vis[sr][sc]=1;
    v[sr][sc]=newcolor;
    int dx[]={1,-1,0,0};
    int dy[]={0,0,-1,1};
    for(int i=0;i<4;i++)
    {
        int x=sr+dx[i];
        int y=sc+dy[i];
        if(x>=0&&y>=0&&x<n&&y<m&&(!vis[x][y])&&(v[x][y]==oldcolor))
        {
            ankit(v,vis,x,y,n,n,oldcolor,newcolor);
        }
    }

}
int main()
{
    vector<vector<int>>v {{1,1,1},{1,1,0},{1,0,1}};
    int n=v.size();
    int m=v[0].size();
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    vector<vector<int>>vis(n,vector<int>(m,0));
    int sr=0;
    int sc=0;
    int oldcolor=v[sr][sc];
    ankit(v,vis,sr,sc,n,m,oldcolor,2);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
   
    return 0;
}