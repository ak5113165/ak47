#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={4,1,1,1,2,3,5};
    int k=5;
    int i=0;
    int j=0;
    int ans=INT_MIN;
    int sum=0;
    while(j<arr.size())
    {
        sum+=arr[j];
        if(sum<k)
        {
            j++;
        }
        else if(sum==k)
        {
            ans=max(ans,j-i+1);
            j++;
        }
        else if(sum>k)
        {
            while (sum>k)
            {
                sum=sum-arr[i];
                i++;
            }
            j++;
            
        }

    }
    cout<<ans;
    return 0;
}