//Segment tree help us to do the range queries in O(log(n))

//The code below is for finding the minimum value
//Pseudocode for building the segment tree

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
