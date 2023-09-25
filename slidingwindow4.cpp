#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int n = arr.size();
    int i = 0;
    int j = 0;
    deque<int> l;//list<int>l;
    vector<int> ans;
    while (j < n)
    {
        while (l.size() > 0 && l.back() < arr[j])
        {
            l.pop_back();
        }
        l.push_back(arr[j]);

        if (j - i + 1 < k)
            j++;
        else if(j-i+1==k)
        {
            ans.push_back(l.front());
            if (arr[i] == l.front())
                l.pop_front();

            i++;
            j++;
        }
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}