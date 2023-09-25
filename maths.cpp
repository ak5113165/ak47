#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin >> num;
    vector<int> d(10);
    bool sign = num > 0;
    if (!sign)
        num = -num;
    while (num)
    {
        d[num % 10]++;
        num /= 10;
    }

    if (sign)
    {
        long ans = 0;
        for (int i = 1; i < 10; ++i)
        {
            if (d[i] > 0)
            {
                ans = i;
                d[i]--;
                break;
            }
        }
        for (int i = 0; i < 10; ++i)
        {
            while (d[i] > 0)
            {
                ans = ans * 10 + i;
                d[i]--;
            }
        }
        cout<<ans;
    }
    else
    {
        long ans = 0;
        for (int i = 9; i >= 0; --i)
        {
            while (d[i] > 0)
            {
                ans = ans * 10 + i;
                d[i]--;
            }
        }
        cout<<-ans;
    }
    return 0;
}