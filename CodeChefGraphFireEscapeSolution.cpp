#include<bits\stdc++.h>
using namespace std;
vector<int>nodes(2001);
int visited[2001];
int cc_size;
void dfs(int u) {
	visited[u] = 1;
	cc_size++;
	for (int v : nodes[u]) {
		if (visited[v] == 0)dfs(u);
	}
}
int main() {
	int t, n, m, a, b;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			visited[i] = 0, nodes[i].clear();
		}
		for (int i = 1; i <= m; i++)
			cin >> a >> b, nodes[a].push_back(b);
		int count = 0;
		long long int res = 1;
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0) {
				cc_size = 0;
				dfs(i), count++;
				res = (res * cc_size) % mod 1e9 + 7;
			}
		}
		cout << count << " " << res << endl;
	}

	return 0;
}