//Segment tree help us to do the range queries in O(log(n))

//The code below is for finding the minimum value
//Pseudocode for building the segment tree

/*
int buildTree(int si, int ss, int se) {
	if (ss == se)
		st[si] = arr[ss];
	int mid = (ss + se) / 2;

	buildTree(2 * si, ss, mid);
	buildTree(2 * si + 1, mid + 1, se);

	st[si] = min(st[2 * si], st[2 * si + 1]);
}


//Pseudocode for carrying out the querry part in the ranges
int query(int si, int ss, int se, int qs, int qe) {
	if (qs > se || qe < ss)return INF; //completely outside
	if (ss >= qs && se <= qe)return st[si]; //completely inside

	int mid = (ss + se) / 2;
	int l = query(2 * si, ss, mid, qs, qe);
	int r = query(2 * si + 1, mid + 1, se, qs, qe);

	return min(l, r);

}

#include<bits/stdc++.h>
using namespace std;

int main() {
	return 0;
}

*/


/*

//The following is a practice problem from spoj
#include<bits/stdc++.h>
using namespace std;
int ar[100001], st[400004];
void buildST(int si, int ss, int se) {
	if (ss == se) {
		st[si] = ar[ss];
		return;
	}
	int mid = (ss + se) / 2;
	buildST(2 * si, ss, mid);
	buildST(2 * si + 1, mid + 1, se);

	st[si] = min(st[2 * si], st[2 * si + 1]);
}

int query(int si, int ss, int se, int qs, int qe) {
	if (ss > qe || se < qs)return INT_MAX;
	if (ss >= qs && se <= qe)return st[si];

	int mid = (ss + se) / 2;
	return min(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
}

int main() {
	int n, q, l, r;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ar[i];
	buildST(1, 1, n);
	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << query(1, 1, n, l + 1 , r + 1 ) << endl;
	}
	return 0;
}

*/

/*

//To perform point update, we use the following pseudo code

void update(int si, int ss, int se, int qi) {
	if (ss == se) {
		st[si] = ar[ss];
	}

	int mid = (ss + se) / 2;
	if (qi <= mid)update(2 * si, ss, mid, qi);
	else
		update(2 * si + 1, mid + 1, se, qi);
	st[si] = min(st[2 * si], st[2 * si + 1]);
}

*/


//HackerEarth problem of helping Ashu
#include<bits/stdc++.h>
using namespace std;
int ar[100001];
pair<int, int>st[400004];

void build(int si, int ss, int se) {
	if (ss == se) {
		if (ar[ss] % 2) {
			st[si] = {1, 0};
		}
		else
			st[si] = {0, 1};
		return;
	}
	int mid = (ss + se) / 2;
	build(2 * si, ss, mid);
	build(2 * si + 1, mid + 1, se);

	st[si].first = st[2 * si].first + st[2 * si + 1].first;
	st[si].second = st[2 * si].second + st[2 * si + 1].second;
}

void update(int si, int ss, int se, int qi, int newVal) {
	if (ss == se) {
		if (ar[ss] % 2)
			st[si] = {0, 1};
		else
			st[si] = {1, 0};
		ar[ss] = newVal;
		return;
	}
	int mid = (ss + se) / 2;
	if (qi <= mid)
		update(2 * si, ss, mid, qi, newVal);
	else
		update(2 * si + 1, mid + 1, se, qi, newVal);
	st[si].first = st[2 * si].first + st[2 * si + 1].first;
	st[si].second = st[2 * si].second + st[2 * si + 1].second;
}

int getEven(int si, int ss, int se, int qs, int qe) {
	if (ss > qe || se < qs)
		return 0;
	if (ss >= qs && se <= qe)return st[si].second;

	int mid = (ss + se) / 2;
	int l = getEven(2 * si, ss, mid, qs, qe);
	int r = getEven(2 * si + 1, mid + 1, se, qs, qe);
	return l + r;
}

int getOdd(int si, int ss, int se, int qs, int qe) {
	if (ss > qe || se < qs)
		return 0;
	if (ss >= qs && se <= qe)return st[si].first;

	int mid = (ss + se) / 2;
	int l = getOdd(2 * si, ss, mid, qs, qe);
	int r = getOdd(2 * si + 1, mid + 1, se, qs, qe);
	return l + r;
}

int main() {
	int n, q, query_code, l, r;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ar[i];
	build(1, 1, n);
	cin >> q;
	while (q--) {
		cin >> query_code;
		if (query_code == 0) {
			cin >> l >> r;
			if ((ar[l] % 2) == (r % 2))continue;
			else update(1, 1, n, l, r);
		}
		else if (query_code == 1) {
			cin >> l >> r;
			cout << getEven(1, 1, n, l, r) << endl;
		}
		else {
			cin >> l >> r;
			cout << getOdd(1, 1, n, l, r) << endl;
		}

	}

	return 0;
}

//Lazy propagation
//In the worst the range update using the before method would take
//O(nlog(n)) when updating the whole range but the lazy propagation
//will take O(log(n))
//The main idea of the lazy propagation is to update only when needed
//Only update if the point lies within the query range

#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int st[400004], lazy[400004];

void build(int si, int ss, int se) {
	if (ss == se) {
		st[si] == arr[ss];
		return;
	}
	int mid = (ss + se) / 2;
	build(2 * si, ss, mid);
	build(2 * si + 1, mid + 1, se);

	st[si] = st[2 * si] + st[2 * si + 1];
}

int query(int si, int ss, int se, int qs, int qe) {
	if (lazy[si] != 0) {
		int dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);
		if (ss != se)
			lazy[2 * si] += dx, lazy[2 * si + 1] += dx;
	}
	if (ss > qe || se < qs)return 0;
	if (ss >= qs && se <= qe)
		return st[si];
	int mid = (ss + se) / 2;
	return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);

}

void update(int si, int ss, int se, int qs, int qe, int val) {
	if (lazy[si] != 0) {
		int dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);

		if (ss != se)
			lazy[2 * si] += dx, lazy[2 * si + 1] += dx;
	}

	if (ss > qs || se < qs)return;

	if (ss >= qs && se <= qe) {
		int dx = (se - ss + 1) * val;
		st[si] += dx;
		if (ss != se)
			lazy[2 * si] += val, lazy[2 * si + 1];
		return;
	}
	int mid = (ss + se) / 2;
	update(2 * si, ss, mid, qs, qe, val);
	update(2 * si + 1, mid + 1, se, qs, qe, val);

	st[si] = st[2 * si] + st[2 * si + 1];
}

int main() {
	int n, q, code, l, r, val;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	while (q--) {
		cin >> code;
		if (code == 1) {
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;
		}
		else {
			cin >> l >> r;
			update(1, 1, n, l, r, val);
		}

	}
	return 0;
}