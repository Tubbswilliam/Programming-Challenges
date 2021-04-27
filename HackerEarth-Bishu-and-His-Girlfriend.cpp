/*
Problem

Bishu and his Girlfriend
(HackerEarth)
*/

#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];//adjacency list
int vis[10001];//visited array
int dis[10001];//distance array of each node from the source


void dfs(int node, int dist) {
	vis[node] = 1;
	dis[node] = dist;

	for (auto v : adj[node]) {
		if (!vis[v])
			dfs(v, dis[node] + 1);
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

	int nodes, q, a, b;
	cin >> nodes;
	for (int i = 1; i <= nodes - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);

	///////////////Querying the given cities
	cin >> q;
	int res = -2;
	int mindis = 100001;
	while (q--) {
		int cityid;
		cin >> cityid;
		if (dis[cityid] < mindis) {
			mindis = dis[cityid];
			res = cityid;
		}
		else {
			if (dis[cityid] == mindis && cityid < res)
				res = cityid;
		}
	}

	cout << res << endl;
	return 0;
}