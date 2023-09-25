#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<char, int> f;
    string s="abcabc";
    int l = 0, r = 0, cnt = 0;
    int n = s.size();
    while (r < n)
    {
        f[s[r]]++;
        while (f['a'] && f['b'] && f['c'])
        {
            cnt += n - r;
            f[s[l++]]--;
        }
        r++;
    }
    cout<<cnt;
    return 0;
}