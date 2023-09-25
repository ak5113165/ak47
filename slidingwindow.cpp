#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "aababcabc";
    int cnt = 0, n = s.size();
    unordered_map<char, int> map;
    for (int i = 0; i < n; i++)
    {
        map[s[i]]++;
        if (i > 2 and --map[s[i - 3]] == 0)
        {
            map.erase(s[i - 3]);
        }

        if (map.size() == 3)
            cnt++;
    }
    cout << cnt;
    return 0;
}