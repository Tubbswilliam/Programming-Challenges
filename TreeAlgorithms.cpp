//Finding a centroid
//A centroid is a point that when removed the created connected component component
//doesn't have size greater than 2 where N is size of the tree.
//You need to calculate the subtree size of each node.
#include<bits/stdc++.h>
using namespace std;
int sub[2000002];
int n;
vector<int>ar[2000001];

void subsize(int node, int par) {
	sub[node] = 1;
	for (int child : ar[node]) {
		if (child != par) {
			subsize(child, node);
			sub[node] += sub[child];
		}
	}
}
int centroid(int node, int par) {
	for (int child : ar[node]) {
		if (child != par && sub[child] > n / 2)return centroid(child, node);
	}
	return node;
}

int main() {
#ifndef ONLINE_JUDGE
//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> n;
	//Read in the graph
	for (int i = 0; i < n; i++) {
		cin >> a >> b
		    ar[a].push_back(b), ar[b].push_back(a);
	}
	subsize(1, -1);
	cout << centroid(1, -1);


	return 0;
}
