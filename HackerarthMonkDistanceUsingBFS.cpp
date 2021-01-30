#include<bits\stdc++.h>
using namespace std;
/*Calculating the subtree size of a tree.
Lets first look at the pseudoCode.
*/
vector<int> adj[10001];
int visited[10001] , dist[10001];

void bfs(int node) {
	queue<int>Q;
	Q.push(node);
	visited[node] = 1;
	dist[node] = 0;

	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();
		for (int v : adj[curr]) {
			if (visited[v] == 0) {
				Q.push(v);
				dist[v] = dist[curr] + 1;
				visited[v] = 1;
			}
		}
	}

}


int main() {
//	n=the number of nodes
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("inputBFSandDFS.txt", "r", stdin);
	// for writing output to output.txt
	freopen("outputBFSandDFS.txt", "w", stdout);
#endif
	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			adj[i].clear(), visited[i] = 0;
		while (m--)
			cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
		bfs(1);
		cout << "The SSSP distance to n is : " << dist[n] << endl;
	}

	return 0;
}