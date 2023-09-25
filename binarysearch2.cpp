#include <bits/stdc++.h>
using namespace std;
//search in rotated sorted array1
int search(vector<int> &nums, int target)
{

    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int mid;

    //Iterative binary search
    while (left <= right)
    {
        mid = (left + right) / 2;
        //cout<<nums[mid]<<"\n";
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] >= nums[left])
        {
            if (target <= nums[mid] && target >= nums[left])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (target >= nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}
//search in rotated sorted array 2;
int searchduplicates(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int mid;

    //Iterative binary search
    while (left <= right)
    {
        mid = (left + right) / 2;
        //cout<<nums[mid]<<"\n";
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > nums[left])
        {
            if (target < nums[mid] && target >= nums[left])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else if(nums[mid]<nums[left])
        {
            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
        else
        {
            left++;
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {11, 12, 15, 18, 2, 4, 5, 8};
    int target = 5;
    cout << search(nums, target);
    vector<int>arr={2,2,2,0,1,1,1,1,1,1,1};
    int ans=0;
    cout<<searchduplicates(arr,ans);
    return 0;
}