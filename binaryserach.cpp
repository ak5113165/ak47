#include <bits/stdc++.h>
using namespace std;
//find minimum in rotated sorted array;
int bs(vector<int> num)
{
    int start = 0, end = num.size() - 1;
    int ans = 0;
    while (start < end)
    {
        if (num[start] < num[end])
            return num[start];

        int mid = (start + end) / 2;

        if (num[mid] >= num[start])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return num[start];
}
int findMinEle(vector<int> &nums)
{
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    if (nums[start] < nums[end])
        return nums[0];
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
            return nums[mid];
        else if (nums[mid] < nums[end])
            end = mid - 1;
        else if (nums[mid] > nums[end])
            start = mid + 1;
    }
    return 0;
}
int findmax(vector<int> nums)
{
    int low = 0;
    int n = nums.size();
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if (nums[mid] >= nums[next] and nums[mid] >= nums[prev])
        {
            return nums[mid];
        }
        else if (nums[mid] >= nums[low])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> num = {11, 12, 15, 18, 2, 5, 6};
    int ans = 0;
    ans = bs(num);
    int a = findMinEle(num);
    cout << ans;
    cout << a;
    int b = findmax(num);
    cout << b;
    return 0;
}