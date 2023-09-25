#include<bits/stdc++.h>
using namespace std;
int32_t sum (vector <int32_t>& tree, int32_t v, int32_t tl, int32_t tr, int32_t l, int32_t r) {
	if (l > r)
		return 0;
	if (tl == l && tr == r) {
		return tree [v];
	}
	int32_t tm = (tl + tr) / 2;
	return sum(tree, 2 * v + 1, tl, tm, l, min(r, tm)) + sum(tree, 2 * v + 2, tm + 1, tr, max(tm + 1, l), r);
}

void update (vector <int32_t>& tree, int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		tree [v] = val;
	}
	else {
		int32_t tm = (tl + tr) / 2;
		if (pos <= tm)
			update(tree, 2 * v + 1, tl, tm, pos, val);
		else
			update(tree, 2 * v + 2, tm + 1, tr, pos, val);
		tree [v] = tree [2 * v + 1] + tree [2 * v + 2];
	}
}
void solve () {
	int32_t n;
	cin >> n;
	vector <int32_t> perm (n);
	for (int32_t i = 0; i < n; ++i) {
		cin >> perm [i];
		--perm [i];
	}

	vector <int32_t> tree (4 * n, 0);

	for (int32_t i = 0; i < n; ++i) {
		int32_t l = perm [i], r = n - 1;
		int32_t ans = sum(tree, 0, 0, n - 1, l, r);
		cout << ans << ' ';
		update(tree, 0, 0, n - 1, l, 1);
	}

// O(n^2) inverse counting
//	for (int32_t i = 0; i < n; ++i) {
//		int32_t inv = 0;
//		for (int32_t j = 0; j < i; ++j) {
//			if (perm [j] > perm [i])
//				++inv;
//		}
//		cout << inv << ' ';
//	}
}

int main () {
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