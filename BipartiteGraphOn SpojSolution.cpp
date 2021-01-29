#include<bits\stdc++.h>
using namespace std;
vector<int>bugs(2001);
int visited[2001], colour[2001];
bool dfs(int u, int col);
int main() {
	int t, n, m, u, v;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			bugs[i].clear(), visited[i] = 0;
		for (int i = 1; i <= m; i++)
			cin >> a >> b, bugs[a].push_back(b), bugs(b).push_back(a);
		bool flag = true;
		for (int i = 1; i <= n; i++)
			if (visited[i] == 0) {
				bool res = dfs(i, 0);
				if (res == false)
					flsg = false;
			}
		cout << "Scenario #" << t << endl;
		if (flag == false)cout << "Suspicious bugs found!" << endl;
		else
			cout << "No Suspicious bugs found!" << endl;
	}
	return 0;
}
bool dfs(int u, int col) {
	visited[u] = 1;
	colour[u] = col;
	for (int v : bugs[u]) {
		if (visited[v] == 0 && dfs(v, c ^ 1))
			return false;
		else {
			if (col[u] == col[v])return false;
		}
	}
	return true;
}