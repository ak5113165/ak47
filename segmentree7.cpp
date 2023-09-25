#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10;
vector<int> t(maxn << 2), a(maxn);
int n;
void update(int rt, int l, int r, int pos, int new_val)
{
    if (l == r)
    {
        t[rt] = new_val;
        return;
    }
    if (pos <= ((l + r) >> 1))
        update(rt << 1, l, (l + r) >> 1, pos, new_val);
    else
        update((rt << 1) + 1, ((l + r) >> 1) + 1, r, pos, new_val);
    t[rt] = t[rt << 1] + t[(rt << 1) + 1];
}
int query(int rt, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[rt];
    return query(rt << 1, tl, (tl + tr) >> 1, l, min(r, (tl + tr) >> 1)) + query((rt << 1) + 1, ((tl + tr) >> 1) + 1, tr, max(l, ((tl + tr) >> 1) + 1), r);
}
int32_t main()
{
            cin >>n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(1, 1, n, i, 1);
    }
    for(int i=0;i<2*n;i++)
    {
        cout<<t[i]<<" ";
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int l = 1, r = n, pos = n;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (query(1, 1, n, 1, m) >= x)
            {
                pos = min(pos, m);
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << a[pos] << " ";
        update(1, 1, n, pos, 0);
    }
    cout << endl;
}