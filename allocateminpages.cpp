#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> arr, int n, int m, int mid)
{
    int st = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mid)
        {
            st++;
            sum = arr[i];
        }
    }
    return st <= m;
}
int main()
{
    vector<int> arr = {20, 10, 30, 40};
    int n = arr.size();
    int m = 2;
    int sum = 0;
    int ans = 0;
    int maxa = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxa = max(maxa, arr[i]);
    }
    int low = maxa;
    int high = sum;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(arr, n, m, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout<<ans;
    return 0;
}