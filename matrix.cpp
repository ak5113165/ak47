#include <bits/stdc++.h>
using namespace std;
//word serach leetcode breadth first search algorithm
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
    vector<vector<char>> v{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string s = "ABCCED";
    int n = v.size();
    int m = v[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(v, i, j, s))
            {
                ans = 1;
            }
        }
    }
    cout << ans;
    return 0;
}