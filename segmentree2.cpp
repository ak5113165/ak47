#include <bits/stdc++.h>
using namespace std;
vector<long long> tree;
long long query(int node, int low, int high, int query_low, int query_high)
{
    if (query_low <= low && high <= query_high)
    {
        return tree[node];
    }
    if (high < query_low || query_high < low)
    {
        return 0;
    }
    int mid = (low + high) / 2;
    return query(2 * node, low, mid, query_low, query_high) + query(2 * node + 1, mid + 1, high, query_low, query_high);
}
void update(int i, int v, int n)
{
    tree[n + i] = v;
    for (int j = (n + i) / 2; j >= 1; j = j / 2)
    {
        tree[j] = tree[2 * j] + tree[2 * j + 1];
    }
}
int find(int v, int tl, int tr, int k)
{
    if (k > tree[v])
        return -1;
    if (tl == tr)
        return tr;
    int tm = (tl + tr) / 2;
    if (tree[v * 2] >= k)
        return find(v * 2, tl, tm, k);
    else
        return find(v * 2 + 1, tm + 1, tr, k - tree[v * 2]);
}
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (__builtin_popcount(n) != 1)
    {
        a.push_back(0);
        n++;
    }
    tree.resize(2 * n);
    for (int i = 0; i < n; i++)
    {
        tree[n + i] = a[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    while(q--)
    {
         int op;
        cin>>op;
        if(op==1)
        {
            int i;
            cin>>i;
            a[i]=1-a[i];
            update(i,a[i],n);
        }
        else
        {
            int k;
            cin>>k;
            cout<<find(1,0,n-1,k)<<"\n";
        }
    }

    return 0;
}