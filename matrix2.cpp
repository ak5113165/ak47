#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<char>> &board, int i, int j, string &word)
{
    if (!word.size())
    {
        return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
    {
        return false;
    }
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ret = dfs(board, i - 1, j, s) || dfs(board, i + 1, j, s) || dfs(board, i, j - 1, s) || dfs(board, i, j + 1, s);
    board[i][j] = c;
    return ret;
}
int main()
{
    vector<vector<char>>v
    {
      {'o','a','a','n'},
      {'e','t','a','e'},
      {'i','h','k','r'},
      {'i','f','l','v'}
    };
    // vector<vector<char>>v{
    //     {'a','b'},
    //     {'c','d'}
    // };
    vector<string> s={"oath","pea","eat","rain"};
    vector<string>res;
    int n=v.size();
    int m=v[0].size();
    int z=s.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<z;k++)
            {
                if(dfs(v,i,j,s[k]))
                {
                    res.push_back(s[k]);
                }
            }
        }
    }
    if(res.empty())
    {
        cout<<"heyu";
    }
    sort(res.begin(),res.end());
    for(auto x:res)
    {
        cout<<x<<" ";
    }
    return 0;
}