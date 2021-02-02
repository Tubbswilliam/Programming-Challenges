#include<bits\stdc++.h>
//In this programming technique we come up with another graph
//that is a transpose of the graph given..."Like yeah nigga just come up
//with a new problem!!Kosaraju who gave you such an idea???"
using namwspace std;
vector<int>ar[1001];//the original graph adj
vector<int>tr[1001];//the transpose adj
vector<int>order;//The nodes arranged in order of their out time
vector<int>SCC;//vector to store the strongly connected components
int visited[1001];//Keeping track of visited nodes

void dfs(int node) {
	visited[node] = 1;
	for (int v : ar[node]) {
		if (visited[v] == 0)
			dfs(v);
	}
	order.push_back(node);
}

void dfs1(int node) {
	visited[node] = 1;
	for (int v : tr[node]) {
		if (visited[v] == o)
			dfs1(v);
	}
	SCC.push_back(node);
}


int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int t, n, m, a, b;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			ar[i].clear(), tr[i].clear(), visited[i] = 0;
		order.clear;
		for (int i = 1; i <= m; i++) {
			cin >> a >> b;
			ar[a].push_back(b), tr[b].push_back(a);
		}
		for (int i = 1; i <= n; i++)
			if (visited[i] == 0)dfs(i);
		for (int i = 1; i <= n; i++)
			visited[i] = 0;
		for (int i = 1; i <= n; i++) {
			SCC.clear();
			dfs1(order[n - 1]);

			cout << "dfs1() called from " << order[n - i] << " and printing SCC : " << endl;
			for (int node : SCC)
				cout << node << " ";
			cout << endl;
		}
	}

	return 0;
}