/*
Problem

Given n, i.e. total number of nodes in an undirected graph numbered from 1 to n and an integer e,
 i.e. total number of edges in the graph. Calculate the total number of connected components in the graph.
A connected component is a set of vertices in a graph that are linked to each other by paths.

*/

#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100001];
int vis[10001];

void dfs(int node) {
	vis[node] = 1;

	for (auto v : adj[node]) {
		if (!vis[v])
			dfs(v);
	}

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

	int nodes, edges, a, b;
	int c_count = 0; //connected components count;
	cin >> nodes >> edges;
	for (int i = 1; i <= edges; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= nodes; i++) {
		if (!vis[i]) {
			dfs(i);
			c_count++;
		}
	}

	cout << c_count << endl;

	return 0;
}