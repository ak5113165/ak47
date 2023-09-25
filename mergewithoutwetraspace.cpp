#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};
    int n = arr1.size();
    int m = arr2.size();
    int i = n - 1;
    int j = 0;
    while (i >= 0 && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else
        {
            j++;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    vector<int>v;
    v.insert(v.begin(),arr1.begin(),arr1.end());
    v.insert(v.end(),arr2.begin(),arr2.end());
    for(auto x:arr1)
    {
        cout<<x<<" ";
    }
    for(auto x:arr2)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    for (auto x : v)
    {
        cout << x;
    }
    return 0;
}