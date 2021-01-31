#include<bits\stdc++.h>
using namespace std;
vector<int>towns[100001];
int in[100001], low[100001], visited[100001], timer;
bool hasBridge;
vector<pair<int, int>>edgeList;

void dfs(int node, int par) {
	vis[node] = 1;
	in[node] = low[node] = timer++;
	for (int v : ar[node]) {
		if (v == par)continue;
		if (visited[v]) {
			low[node] = min(low[node], in[v]);
			if (in[node] > in[v])
				edgeList.push_back({node, v});
		}
		else {
			dfs(v, node);
			if (low[v] > in[node]) {
				hasBridge = true;
				return;
			}
			edgeList.push_back({node, v});
			low[node] = min(low[node], low[v]);
		}
	}
}
int main() {
	int n, m, a, b;
	cin >> n >> m;
	while (m--)
		cin >> a >> b, ar[a].push_back(b), ar[b].push_back(a);
	dfs(1 - 1);
	if (hasBridge)
		cout << "0" << endl;
	else
		for (pair<int, int>e : edgeList)
			cout << e.first << " " << e.second << endl;


	return 0;
}