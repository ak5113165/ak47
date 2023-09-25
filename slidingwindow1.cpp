#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={2,5,1,8,2,9,1};
    int n=arr.size();
    int k=3;
    int i=0;
    int j=0;
    int sum=0;
    int ans=INT_MIN;
    while(j<n)
    {
        sum+=arr[j];
        if(j-i+1<k)
        {
            j++;
        }
        if(j-i+1==k)
        {
            ans=max(ans,sum);
            sum=sum-arr[i];
            i++;
            j++;
        }
    }
    cout<<ans;
    return 0;
}