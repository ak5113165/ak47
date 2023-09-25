#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a = "CCABBAbBCABB";
    // int j=s.size()-1;
    int ans = INT_MAX;
    int n = a.size();
    int i = 0, j = 0;
    int p = INT_MAX;
    int c;
    unordered_map<char, int> mp;
    for (char x : a)
        mp[x]++;
    int k = mp.size();
    mp.clear();
    while (j < n)
    {
        mp[a[j]]++;
        while (mp.size() == k)
        {
            //   p=min(p,j-i+1);
            ans=min(ans,j-i+1);
            if (j - i + 1 < p)
            {
                p = j - i + 1;
                c = i;
            }
            mp[a[i]]--;
            if (mp[a[i]] == 0)
                mp.erase(a[i]);
            i++;
        }
        j++;
    }
    cout<<p;
    cout<<ans;
    cout<<a.substr(c,p);
    return 0;
}