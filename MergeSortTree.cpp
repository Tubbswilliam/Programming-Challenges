//This algorithm is almost similar to segment tree but it helps us
//to answer some of the specific questions such as element less or greater than k, unique elements
//within a certain range etc.
//time complexity is O(log(n)) while the space complexity is o(n log (n))

#include<bits/stdc++.h>
using namespace std;
int ar[100001];
vector<int>st[400004];

void build(int si, int ss, int se) {
	if (ss == se) {
		st[si] = push_back(ar[ss]);
		return;
	}

	int mid = (ss + se) / 2;
	build(2 * si, ss, mid);
	build(2 * si + 1, mid + 1, se);

	int i = 0;
	int j = 0;
	while (i < st[2 * si].size() && j < st[2 * si + 1].size()) {
		if (st[2 * si][i] <= st[2 * si + 1][j])
			st[si].push_back(st[2 * si][i]), i++;
		else
			st[si].push_back(st[2 * si + 1][j]), j++;
	}
	while (i < st[2 * si].size())
		st[si].push_back(st[2 * si][i]), i++;
	while (j < st[2 * si + 1].size())
		st[si].push_back(st[2 * si + 1][j]), j++;

}

int query(int si, int ss, int se, int qs, int qe, int k) {
	if (ss > qe || se < qs)return 0;
	if (ss >= qs && se <= qe) {
		int res = upper_bound(st[si].begin(), st[si].end(), k - 1) - st[si].begin();
		return res;
	}
	int mid = (ss + se) / 2;
	int l = query(2 * si, ss, mid, qs, qe, k);
	int r = query(2 * si + 1, mid + 1, se, qs, qe, k);
	return l + r;

}

int main() {
	int n, q, l, r, k;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)cin >> ar[i];
	build(1, 1, n);

	while (q--) {
		cin >> l >> r >> k;
		cout << query(1, 1, n, l, r, k) << endl;
	}
	return 0;
}