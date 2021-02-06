#include<bits/stdc++.h>
using namespace std;
/*
It can be proved every graph with  nodes and  connected components have at least  edges.

So if graph have at most  connected components the answer is m-n+k, else is -1.
*/
vector<int> adj[1000001];
int visited[1000001];

void dfs(int u) {
	visited[u] = 1;
	for (int v : adj[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main() {
	int n, m, k, a, b;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a)

	}
	int connectedComp = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			connectedComp++;
		}
	}
	if (connectedComp > k)
		cout << -1 << endl;
	else
		cout << m - n + k << endl;

	return 0;
}