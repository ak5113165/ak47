#include<bits/stdc++.h>
using namespace std;
//longest substring with k unique character;
int main()
{
    string s="ddacbbaccdedacebb";
    int k=3;//output=7;
    int i=0;
    int j=0;
    map<char,int>mp;
    int ans=0;
    while (j<s.size())
    {
        mp[s[j]]++;
        if(mp.size()<k)
        {
            ans=max(ans,j-i+1);
            j++;
        }
        else if(mp.size()==k)
        {
            ans=max(ans,j-i+1);
            j++;
        }
        else if(mp.size()>k)
        {
            while(mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    cout<<ans;
    return 0;
}