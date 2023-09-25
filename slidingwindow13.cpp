#include <bits/stdc++.h>
using namespace std;
//longest character replacement leetcode 424or 2024
int main()
{
    string s = "AABABBA";
    int k = 1;
    int j = 0, n = s.size();
    unordered_map<char, int> fre;
    int maxi = 0, ans = 0;
    int i = 0;
    while (j < n)
    {
        fre[s[j]]++;
        maxi = max(maxi, fre[s[j]]);
        if (j - i + 1 - maxi <= k)
        {
            ans = max(j - i + 1, ans);
        }
        if ((j - i + 1) - maxi > k) // here you don't need to update the maxi because if you can't get greater or equal maxi further it's answer would be biggest  :)
        {
            fre[s[i]]--;
            i++;
        }
        j++;
    }
    cout << ans;
    return 0;
}