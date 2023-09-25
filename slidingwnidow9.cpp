#include<bits/stdc++.h>
using namespace std;
//distinct elements in each window of size k;
int main()
{
    vector<int>nums={2,5,5,6,3,2,3,2,4,5,2,2,2,2,3,6};
    int n=nums.size();
    int i=0;
    int j=0;
    int k=4;
    vector<int>v;
    unordered_map<int,int>mp;
    while(j<nums.size())
    {
        mp[nums[j]]++;
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1==k)
        {
            v.push_back(mp.size());
            mp[nums[i]]--;
            if(mp[nums[i]]==0)
            {
                mp.erase(nums[i]);
            }
            i++;
            j++;
        }
        
    }
    for(auto x:v)
    {
       cout<<x<<" ";
    }
    return 0;
}