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
    long long sum=query(2 * node, low, mid, query_low, query_high)+query(2 * node + 1, mid + 1, high, query_low, query_high);
    return tree[node]+sum;
}
void update1(int node, int low, int high, int query_low, int query_high,int v)
{
    if (query_low <= low && high <= query_high)
    {
        tree[node]+=v;
        return ;
    }
    if (high < query_low || query_high < low)
    {
        return ;
    }
    int mid = (low + high) / 2;
    update1(2 * node, low, mid, query_low, query_high,v);
    update1(2 * node + 1, mid + 1, high, query_low, query_high,v);
    // tree[node]=tree[2*node]+tree[2*node+1];
}
void update(int i, int v, int n)
{
    tree[n + i] = v;
    for (int j = (n + i) / 2; j >= 1; j = j / 2)
    {
        tree[j] = tree[2 * j]+tree[2 * j + 1];
    }
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
    // for (int i = n - 1; i >= 1; i--)
    // {
    //     tree[i] = min(tree[2 * i],tree[2 * i + 1]);
    // }
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
           int low,high,u;
           cin>>low>>high>>u;
           low--;
           high--;
          update1(1,0,n-1,low,high,u);
        }
        else
        {
           int k;
           cin>>k;
           k--;
           cout<<query(1,0,n-1,k,k);
           cout<<endl;
        }
    }

    return 0;
}