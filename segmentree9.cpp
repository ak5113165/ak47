#include <bits/stdc++.h>
using namespace std;
void build(vector<int> &tree, vector<int> &a, int v, int tl, int tr)
{
    if (tl == tr)
        tree[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(tree, a, 2 * v + 1, tl, tm);
        build(tree, a, 2 * v + 2, tm + 1, tr);
        tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    }
}
int first_element_at_least_x(vector<int> &tree, int v, int tl, int tr, int x, int l)
{
    if (tr < l)
        return -1;
    if (x > tree[v])
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    int res = first_element_at_least_x(tree, 2 * v + 1, tl, tm, x, l);
    if (res == -1)
        res = first_element_at_least_x(tree, 2 * v + 2, tm + 1, tr, x, l);
    return res;
}
void update(vector<int> &tree, int v, int tl, int tr, int pos, int val)
{
    if (tl == tr)
        tree[v] = val;
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(tree, 2 * v + 1, tl, tm, pos, val);
        else
            update(tree, 2 * v + 2, tm + 1, tr, pos, val);
        tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    }
}

// int find(vector<int> &tree, int v, int tl, int tr, int k)
// {
//     if (k > tree[v])
//         return -1;
//     if (tl == tr)
//         return tl;
//     int tm = (tl + tr) / 2;
//     if (tree[2 * v + 1] >= k)
//         return find(tree, 2 * v + 1, tl, tm, k);
//     else
//         return find(tree, 2 * v + 2, tm + 1, tr, k - tree[2 * v + 1]);
// }

void solve()
{
    int n, m;
	cin >> n >> m;
	vector <int> a (n);
	for (int i = 0; i < n; ++i) {
		cin >> a [i];
	}

	vector <int> tree (4 * n, 0);
	build(tree, a, 0, 0, n - 1);

	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int pos, val;
			cin >> pos >> val;
			update(tree, 0, 0, n - 1, pos, val);
		}
		else if (t == 2) {
			int x, l;
			cin >> x >> l;
			cout << first_element_at_least_x(tree, 0, 0, n - 1, x, l) << '\n';
		}
		else
			assert(false);
	}
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.precision(10);
    std::cout << std::fixed << std::boolalpha;

    int t = 1;
    //	std::cin >> t;
    while (t--)
        solve();

    return 0;
}