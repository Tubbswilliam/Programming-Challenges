#include<bits\stdc++.h>
using namespace std;
class Graph {
	int m_v;
	vector<vector<int>>m_adj;
public:
	Graph(int v): m_v(v), m_adj(v) {

	}
	void addEdge(int u, int v) {
		m_adj[u].push_back(v);//Directed graph
	}
	void BFS(int s) {
		queue<int>Q;
		vector<bool>visited(m_v, false);
		Q.push(s);
		visited[s] = true;
		while (!Q.empty()) {
			int v = Q.front();
			Q.pop();
			cout << v << endl;
			for (auto u : m_adj[v]) {
				if (!visited[u]) {
					Q.push(u);
					visited[u] = true;
				}
			}

		}

	}
};
int main() {
// #ifndef ONLINE_JUDGE
// 	//for getting input from input.txt
// 	freopen("input1.txt", "r", stdin);
// 	// for writing output to output.txt
// 	freopen("output1.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Graph G(5);
	G.addEdge(0, 1);
	G.addEdge(0, 3);
	G.addEdge(1, 2);
	G.addEdge(3, 2);
	G.addEdge(3, 4);
	G.BFS(0);


	return 0;
}

