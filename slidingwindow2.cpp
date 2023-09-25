#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {12,-1,-7,8,-15,-30,16,28};
    int n = arr.size();
    int k = 3;
    // deque<int> q;

    // // traverse the first window
    // for (int i = 0; i < k; i++) {
    //     // if the current element is negative add it to the end of deque
    //     if (arr[i] < 0)
    //         q.push_back(i);
    // }

    // // if deque is not empty, front of deque is the index of first negative element
    // // else there is no negative element in this window
    // if (!q.empty())
    //     cout<<arr[q.front()]<<" ";
    // else
    //     cout<<"0 ";

    // for (int i = k; i < n; i++) {
    //     // remove previous window elements
    //     while (!q.empty() && q.front() <= (i - k)) {
    //         q.pop_front();
    //     }

    //     // if the current element is negative, add it to the deque
    //     if (arr[i] < 0)
    //         q.push_back(i);

    //     // if deque is not empty, front of deque is the index of first negative element
    //     // else there is no negative element in this window
    //     if (!q.empty())
    //         cout<<arr[q.front()]<<" ";
    //     else
    //         cout<<"0 ";
    // }
    deque<int> q;
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n and j < n)
    {
        // calculation
        if (arr[j] < 0)
        {
            q.push_back(arr[j]);
        }
        // the first window
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (q.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(q.front());
                if (q.front() == arr[i])
                {
                    q.pop_front();
                }
            }
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