#include<bits/stdc++.h>
using namespace std;
bool ok(vector<int>nums,int d,int k)
{
    int count=0;
    int l=0;
    int r=1;
    int n=nums.size();
    while(r<n)
    {
       if(nums[r]-nums[l]<=d)
       {
           count+=(r-l);
           r++;
       }
       else
       {
           l++;
       }
       
    }
    // cout<<count;
    cout<<endl;
    return count>=k;
}
int main()
{
    vector<int>nums={1,6,1};
    int k=3;
    sort(nums.begin(),nums.end());
    int low=0;
    int ans=-1;
    int high=nums.back()-nums[0];
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(ok(nums,mid,k))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<ans;
    return 0;
}