#include<bits/stdc++.h>
using namespace std;
int main()
{
    string keyboard="abcdefghijklmnopqrstuvwxy";
    string text="codeforces";
    int ans=0;
    unordered_map<char,int>mp;
    sort(keyboard.begin(),keyboard.end());
    for(int i=0;i<keyboard.size();i++)
    {
        mp[keyboard[i]]=i;
    }
    int prev=0;
    for(int i=0;i<text.size();i++)
    {
        ans+=abs(mp[text[i]]-prev);
        prev=mp[text[i]];
    }
    cout<<ans;
    return 0;
}