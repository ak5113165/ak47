#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct item
{
    ll seg,pref,suff,sum; // val1 is acutal value of node val2 is count.
};
struct segtree
{
    int n;
    vector<item> t;
    void init(int sz)
    {
        n = sz;
        t.resize(4 * n + 5);
    }
    item neutral = {0,0,0,0};// check here
    item single(int v)
    {
        if(v>0)
        {
            return {v,v,v,v};
        }
        else{
            return {0,0,0,v};
        }
    }
    item merge(item a, item b)
    { // check this func, this is for min and its count on segment.
        return {
            max(a.seg,max(b.seg,a.suff+b.pref)),
            max(a.pref,a.sum+b.pref),
            max(b.suff,b.sum+a.suff),
            a.sum+b.sum
        };
    }

    void build(int v, int tl, int tr, vector<int> &arr)
    {
        if (tl == tr)
        {
            t[v] = single(arr[tl]);
            return;
        }
        ll tm = (tr + tl) / 2;
        build(2 * v, tl, tm, arr);
        build(2 * v + 1, tm + 1, tr, arr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
    void build(vector<int> &arr)
    {
        n = arr.size();
        init(n);
        build(1, 0, n - 1, arr);
    }
    void update(int v, int tl, int tr, int id, int val)
    {
        if (id < tl || id > tr)
            return;
        if (tl == tr)
        {
            t[v] = single(val);
            return;
        }
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, id, val);
        update(2 * v + 1, tm + 1, tr, id, val);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
    void update(int id, int val)
    {
        update(1, 0, n - 1, id, val);
    }
    item query(int v, int tl, int tr, int l, int r)
    {
        if (tl >= l && tr <= r)
            return t[v];
        if (tl > r || tr < l)
            return neutral;
        int tm = (tl + tr) / 2;
        return merge(query(2 * v, tl, tm, l, r), query(2 * v + 1, tm + 1, tr, l, r));
    }
    item query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
    
};
int main()
{
    ll n,m;
    cin>>n>>m;
    segtree st;
    st.init(n);
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    st.build(a);
    cout<<st.query(0,n).seg<<"\n";
    while(m--)
    {
        int i,v;
        cin>>i>>v;
        st.update(i,v);
        cout<<st.query(0,n).seg<<"\n";
    }
    return 0;
}