#include <bits/stdc++.h>
using namespace std;
//leetcode no of closed islands;
bool dfs(int i,int j,vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    if(i<0||i>=n||j<0||j>=m)
    {
        return false;
    }
    if(grid[i][j]==1)
    {
        return true;
    }
    grid[i][j]=1;
    bool up=dfs(i-1,j,grid);
    bool down=dfs(i+1,j,grid);
    bool right=dfs(i,j+1,grid);
    bool left=dfs(i,j-1,grid);
    return up&&down&&left&&right;
}
int main()
{
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}};
        int n=grid.size();
        int ans=0;
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0&&dfs(i,j,grid)==true)
                {
                    ans++;
                }
            }
        }
        cout<<ans;
        cout<<max(0,-2);
    return 0;
}