#include<bits\stdc++.h>
using namespace std;
/*An articulation point is basically
a node which lies on the bridge and its degree is more than one.
*/
vector<int>nodes[100001];
int visited[100001], in[100001], low[100001], timer;
set<int>AP;

void dfs(int node, int par) {
	visited[node] = 1;
	in[node] = low[node] = timer++;
	int vCount = 0;

	for (int v : nodes[node]) {
		if (v == par)continue;
		if (visited[v] == 1) {
			low[node] = min(low[node], in[v]);

		}
		else {
			dfs(v, node);
			vCount++;
			low[node] = min(low[v], low[node]);
			if (in[node] <= low[v] && par != -1)
				AP.insert(node);
		}
	}
	if (par == -1 && vCount > 1)
		AP.insert(node);

}


int main() {
	int n, m, a, b;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		for (int i = 1; i <= n; i++) {
			nodes[i].clear(), visited[i] = 0;
		}
		AP.clear();
		timer = 1;

		for (int i = 1; i <= m; i++)
			cin >> a >> b, nodes[a].push_back(b), nodes[b].push_back(a);
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0)
				dfs(i, -1);
		}
		cout << AP.size() << endl;
	}

	return 0;
}