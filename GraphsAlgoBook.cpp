//Graph Representation
#include<bits/stdc++.h>
using namespace std;

int main() {
//using adjacency matrix
	//Using adjacency array list//One can also use a linked list//
	int n, m;
	vector<int>arr(n + 1);
	while (m--) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	return 0;
}

