#include <bits/stdc++.h>
using namespace std;
int main()
{
    string nums = "aaoao";
    int zero = 0;
    int i = 0;
    int j = 0;
    int k = 1;
    int ans = 0;
    while (j < nums.size())
    {
        if (nums[j] == 'o')
            zero++;
        if (zero < k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (zero == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (zero > k)
        {
            while (zero > k)
            {
                if (nums[i] == 'o')
                {
                    zero--;
                }
                i++;
            }
            j++;
        }
    }
    cout << ans;
    return 0;
}