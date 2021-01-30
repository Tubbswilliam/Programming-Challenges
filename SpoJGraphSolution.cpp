#include<bits\stdc++.h>
using namespace std;
//finding the diameter of a tree
//This is basically the longest path between any two nodes
//Worse algoritm time complexity that mmy stupid head can think of is O(N^2);
//I can better it by using 2 dfs.That will basicaaly take O(N) time complexity.

vector<int>nodes(2001);
int visited[2001];
int maxD, maxNode;

void dfs(int node, int d) {
	visited[node] = 1;
	if (d > maxD)maxD = d, maxNode = node;
	for (int v : nodes[node]) {
		if (visited[v] == 0)
			dfs(v, d + 1);
	}

}
int main() {
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b, nodes[a].push_back(b), nodes[b].push_back(a);
		maxD = -1;
		dfs(1, 0);

		for (int i; i < n; i++) {
			visited[i].clear();
		}
		maxD = -1;
		dfs(1, d + 1);
	}
	cout << maxD;

	return 0;
}