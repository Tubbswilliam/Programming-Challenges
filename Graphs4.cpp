//Bipartite Graph

#include<bits/stdc++.h>
using namespace std;
bool bipartiteBfs(int src, vactor<int>adj[], int color[]) {
	queue<int>q;
	color[src] = 0;
	while (!q.empty()) {
		int node = q.fornt();
		q.pop();

		for (int i : adj[node]) {
			if (color[i] == -1) {
				color[i] == 1 - color[node];
				q.push(i);
			} else if (color[i] == color[node]) {
				return false;
			}
		}
	}

	return true;
}

bool checkBip(vector<int>adj[], int n) {
	int color[n];
	memset(color, -1, sizeof color);
	for (int i = 0; i < n; i++) {
		if (color[i] == -1) {
			if (!bipartiteBfs(i, adj, color)) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int>adj[n];
	for (int i = 0; i < m; i++) {
		int u, v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (checkBip(adj, n)) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}