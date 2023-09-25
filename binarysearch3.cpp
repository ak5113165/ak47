#include <bits/stdc++.h>
using namespace std;
//k closet elemnets
int main()
{
    vector<int> arr = {10,20,30,40,50};
    int n = arr.size();
    int k = 4;
    int x = 45;
    int low = 0;
    int high = n - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            break;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    vector<int> v;
    int left = low- 1;
    int right = low;
    while (left >= 0 && right < n && k > 0)
    {
        if (abs(arr[left] - x) <= abs(arr[right] - x))
        {
            v.push_back(arr[left]);
            left--;
        }
        else
        {
            v.push_back(arr[right]);
            right++;
        }
        k--;
    }
    while (k > 0 && left >= 0)
    {
        v.push_back(arr[left]);
        left--;
        k--;
    }
    while (k > 0 && right < n)
    {
        v.push_back(arr[right]);
        right++;
        k--;
    }
    sort(v.begin(), v.end());
    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}
