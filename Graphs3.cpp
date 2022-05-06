//Cycle detection

#include<bits/stdc++.h>
using namespace std;
class solution {
	bool checkCycle(int i, int v, vector<int>adj[], vector<int>&visited) {
		//create a queue
		queue<pair<int, int>>q;

		visited[s] = 1;
		q.push({s, -1});

		while (!q.empty()) {
			int node = q.front().first;
			int par = q.front().second;
			q.pop();

			for (int i : adj[node]) {
				if (!visited[i]) {
					visited[i] = 1;
					q.push({i, node});
				}
				else if (par != i)
					return true;
			}
		}
		return false;
	}

	bool isCycle(int v, vector<int>adj[]) {
		vector<int>vis(v + 1, 0);
		for (int i = 1; i <= v; i++) {
			if (!vis[i]) {
				if (checkCycle(i, v, adj, vis))
					return true;
			}
		}
	}
};
int main() {
	return 0;
}