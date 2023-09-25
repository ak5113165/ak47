#include <bits/stdc++.h>
using namespace std;
// subaaary product less than k;
int main()
{
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    int i = 0;
    int j = 0;
    int ans = 0;
    int prod = 1;
    int n = nums.size();
    int  left = 0;
    if(k<=1)
    {
        cout<<"0";
    }
    for (int i = 0; i < n; i++)
    {
        prod *= nums[i];
        while (prod >= k)
        {
            prod /= nums[left++];
        }
        ans += i - left + 1;
    }
    cout << ans;
    return 0;
}