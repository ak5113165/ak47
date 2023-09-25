#include<bits/stdc++.h>
using namespace std;
//k closet elements;
int main()
{
    
    vector<int>nums1={1,7,11};
    vector<int>nums2={2,4,6};
    int n=nums1.size();
    int m=nums2.size();
    int k=3;
    priority_queue<pair<int,pair<int,int>>>p;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(p.size()<k)
            {
                p.push(make_pair(nums1[i]+nums2[j],make_pair(nums1[i],nums2[j])));
            }
            else if(nums1[i]+nums2[j]<p.top().first)
            {
                p.pop();
                p.push(make_pair(nums1[i]+nums2[j],make_pair(nums1[i],nums2[j])));
            }
        }
    }
    vector<vector<int>>v;
    while(!p.empty())
    {
       v.push_back({p.top().second.first,p.top().second.second});
       p.pop();
    }
    for(auto x:v)
    {
        for(auto it:x)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
    return 0;
    
}
