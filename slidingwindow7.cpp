#include<bits/stdc++.h>
using namespace std;
//longest substring without repaeting character
int main()
{
    string s="pwwkew";
    int i=0;
    int ans=0;
    int j=0;
    map<int,int>mp;
    while (j<s.size())
    {
        mp[s[j]]++;
        if(mp.size()==j-i+1)
        {
            ans=max(ans,j-i+1);
        }
        else if(mp.size()<j-i+1)
        {
            while(mp.size()<j-i+1)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    cout<<ans;
    
    return 0;

}