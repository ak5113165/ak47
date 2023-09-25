#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "aabaabaa";
    string pattern = "aaba";
    int k = pattern.size();
    unordered_map<char, int> m;
    for (int i = 0; i < pattern.size(); i++)
    {
        m[pattern[i]]++;
    }
    int count = m.size();
    int n = s.size();
    int i = 0;
    int j = 0;
    int ans = 0;
    while (j < s.length())
    {

        if (m.find(s[j]) != m.end())
        {
            m[s[j]]--;
            if (m[s[j]] == 0)
                count--;
        }

        if ((j - i + 1) < k)
            j++;

        else if ((j - i + 1) == k)
        {

            if (count == 0)
                ans++;

            if (m.find(s[i]) != m.end())
            {
                m[s[i]]++;
                if (m[s[i]] == 1)
                    count++;
            }

            i++;
            j++;
        }
    }
    cout << ans;
    return 0;
}