#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {8, 2, 4, 7};
    int limit = 4;
    multiset<int> m;
    int len;
    int ans = 0;
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        m.insert(nums[i]);
        while (!m.empty() && *m.rbegin() - *m.begin() > limit)
            m.erase(m.find(nums[j++]));
        ans = max(ans, i - j + 1);
    }
    int res = 0;
    int minn = INT_MAX;
    int maxx = INT_MIN;
    int left = 0;
    int diff = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        minn = min(minn, nums[right]);
        maxx = max(maxx, nums[right]);
        diff = abs(maxx - minn);
        while ( diff > limit)
        {
            // int last = nums[left++];
            minn = INT_MAX;
            maxx = INT_MIN;
            left++;
            for (int i = left; i <= right; i++)
            {
                minn = min(minn, nums[i]);
                maxx = max(maxx, nums[i]);
            }
            diff =abs(maxx - minn);
        }
        res = max(right - left + 1, res);
    }
    cout << ans;
    cout<<res;
    return 0;
}