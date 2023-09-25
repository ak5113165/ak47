#include <bits/stdc++.h>
using namespace std;
//minimum window substring
int main()
{
    string s = "totmtaptat";
    string t = "tta";
       unordered_map<char, int> m;
    for (auto it : t)
        m[it]++;

    string ans = "";
    int maxlen = INT_MAX;
    int i = 0, j = 0;
    int count = m.size();

    while (j < s.length())
    {
        if (m.find(s[j]) != m.end())
        {
            m[s[j]]--;
            if (m[s[j]] == 0)
                count--;
        }
        while (count == 0 and i <= j)
        {
            if (maxlen > (j - i + 1))
            {
                maxlen = j - i + 1;
                ans = s.substr(i, j - i + 1);
            }
            if (m.find(s[i]) != m.end())
            {
                m[s[i]]++;
                if (m[s[i]] == 1)
                    count++;
            }
            i++;
        }
        j++;
    }

    cout << ans << " " << maxlen;
    return 0;
}
