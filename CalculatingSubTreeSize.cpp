#include<bits\stdc++.h>
using namespace std;
/*Calculating the subtree size of a tree.
Lets first look at the pseudoCode.
*/
vector<int> adj[100001];
int visited[100001] , subsize[100001];

int dfs(int node) {
	visited[node] = 1;
	int currentSize = 1;
	for (int v : adj[node]) {
		if (visited[v] == 0) {
			currentSize += dfs(v);
		}
	}
	subsize[node] = currentSize;
	return currentSize;
}

int main() {
	//n=the number of tree edges in the tree
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("inputBFSandDFS.txt", "r", stdin);
	// for writing output to output.txt
	freopen("outputBFSandDFS.txt", "w", stdout);
#endif
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
	//Call dfs on any root you would like
	//Below i will call it from the root
	dfs(1);
	for (int i = 1; i <= n; i++)
		cout << "SubtreeSize of node : " << i << " is " << subsize[i] << endl;


	return 0;
}