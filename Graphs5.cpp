//Bipartite graph using DFS

#include<bits/stdc++.h>
using namespace std;
bool bipartiteDFS(int node, vector<int>adj[], int color[]) {
	if (color[node] = -1)color[node] = 1;
	for (int i : adj[node]) {
		if (color[i] == -1) {
			color[i] = 1 - color[node];
			if (!bipartiteDFS(i, adj, color)) {
				return false;
			} else if (color[i] == color[node])return false;
		}

	}

	return true;
}

bool checkbipartite(vector<int>adj[], int n) {
	int color[n];
	memset(color, -1, sizeof color);
	for (int i = 0; i < n; i++) {
		if (color[i] == -1) {
			if (!bipartiteDFS(i, adj, color)) {
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
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (checkbipartite(adj, n)) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}