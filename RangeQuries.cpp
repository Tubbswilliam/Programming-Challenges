//Fenwick Tree
/*
#include<bits/stdc++.h>
using namespace std;

int fen[N];

void update(int i, int val) {
	while (i < N) {
		//val is the value to be added or updated
		fen[i] += val;
		i += i + (i & (-i));
	}
}

int sum(int i) {
	int s = 0; //to store the sum
	while (i > 0) {
		s += fen[i];
		i += i - (i & (-i));
	}
	return s;
}


//Binary lifting in fenwick tree
int find(int k) {
	int curr = 0, ans = 0, prevsum = 0;
	for (int i = log2(n); i >= 0; i--) {
		if (ft[curr + (1 << i)] + prevsum < k) {
			curr = curr + (1 << i);
			prevsum += ft[curr];
		}
	}
	return (curr + 1);
}

*/


//Segment tree
#include<bits/stdc++.h>
using namespace std;

int arr[1000001], seg[4 * 1000001];
int lazy[100001];

void build(int ind, int low, int high) {
	if (low == high) {
		seg[ind] = arr[low];
		return;
	}
	int mid = (low + high) / 2;
	build(2 * ind + 1, mid, high);
	build(2 * ind + 2, mid + 1, high);
	seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);

}

/*

int query(int ind, int low, int high, int l, int r) {
	if (low >= l && high <= r)
		return seg[ind];

	if (high < l || r < low) {
		return INT_MIN;
	}

	//in the case of an overLap
	int mid = (low + high) / 2;
	int left = query(2 * ind + 1, low, mid, l, r);
	int right = query(2 * ind + 2, mid + 1, high, l, r);
	return max(left, right);

}
*/

//This is just point update...updating one point only
void pointUpdate(int ind, int low, int high, int node, int val) {
	if (low == high) {
		seg[low] += val;
	}
	else {
		int mid = (low + high) / 2;
		if (node <= mid && node >= low)
			pointUpdate(2 * ind + 1, low, mid, node, val);
		else
			pointUpdate(2 * ind + 2, mid + 1, high, node, val);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2]; //In the case you are trying to et the sum
	}
}


//Lazy propagation useful when updating more than one element in a range
void rangeupdate(int ind, int low, int high, int l, int r, int val) {
	if (lazy[ind] != 0) {
		seg[ind] += (high - low + 1) * lazy[ind];
		if (low != high) {
			lazy[2 * ind + 1] += lazy[ind];
			lazy[2 * ind + 2] += lazy[ind];
		}
		lazy[ind] = 0;
	}
	if (r < low || l > high || low > high)return;

	if (low >= l && high <= r) {
		seg[ind] += (high - low + 1) * val;

		if (low != high) {
			lazy[2 * ind + 1] += lazy[ind];
			lazy[2 * ind + 2] += lazy[ind];
		}
		return;
	}
	int mid = (low + high) >> 1;
	rangeupdate(2 * ind + 1, low, mid, l, r, val);
	rangeupdate(2 * ind + 2, mid + 1, high, l, r, val);
	seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int querySum(int ind, int low, int high, int l, int r, val) {
	if (lazy[ind] != 0) {
		seg[ind] += (high - low + 1) * lazy[ind];
		if (low != high) {
			lazy[2 * ind + 1] += lazy[ind];
			lazy[2 * ind + 2] += lazy[ind];
		}
		lazy[ind] = 0;
	}
	if (r < low || l > high || low > high) return 0;

	if (low >= l && high <= r)
		return seg[ind];

	int mid = (low + high) >> 1;

	return querySum(2 * ind + 1, low, mid, l, r, val) + querySum(2 * ind + 2, mid + 1, high, l, r, val);

}


int main() {
// #ifndef ONLINE_JUDGE
// 	//for getting input from input.txt
// 	freopen("input.txt", "r", stdin);
// 	// for writing output to output.txt
// 	freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//Build the segment tree
	//low is the beginning of the array and high is the end of the array
	build(0, 0, n - 1);

	//You need to query the segment tree
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(0, 0, n - 1, l, r) << endl;
	}

	//pointUpdate(0,0,n-1,node,val)
	return 0;
}




