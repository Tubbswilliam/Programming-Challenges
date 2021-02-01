#include<bits\stdc++.h>
using namespace std;
class Graph {
	int m_v;
	vector<vector<int>>m_adj;
	void OrderVertices(int d, vector<bool>&visited, stack<int>&s) {
		visited[d] = true;
		//cout << u << endl;
		for (int v : m_adj[d]) {
			if (!visited[v])OrderVertices(v, visited, s);
		}
		s.push(d);
	}
	Graph reverseGraph() {
		Graph G(m_v);
		for (int i = 0; i < m_v; i++) {
			for (int u : m_adj[i])
				G.m_adj[u].push_back(i);
		}
		return G;
	}
	void dfs(vector<bool>&visited, int S) {
		visited[S] = true;
		cout << S << " ";
		for (int u : m_adj[S]) {
			if (!visited[u])dfs(visited, u);
		}
	}
public:
	Graph(int v): m_v(v), m_adj(v) {}
	void addEdge(int u, int v) {
		m_adj[u].push_back(v);
		//m_adj[v].push_back(u);
	}
	void SSC() {
		vector<bool>visited(m_v, false);
		stack<int>s;
		for (int i = 0; i < m_v; i++) {
			if (!visited[i])OrderVertices(i, visited, s);

			Graph G = reverseGraph();
			for (int i = 0; i < m_v; i++)
				visited[i] = false;
			while (!s.empty()) {
				int v = s.top();
				s.pop();
				if (!visited[v]) {
					G.dfs(visited, v);
					cout << endl;
				}
			}
		}
	}
};
int main() {
	Graph G(9);
	G.addEdge(0, 1);
	G.addEdge(1, 2);
	G.addEdge(2, 3);
	G.addEdge(3, 0);
	G.addEdge(2, 4);
	G.addEdge(4, 5);
	G.addEdge(5, 6);
	G.addEdge(6, 4);
	G.addEdge(7, 6);
	G.addEdge(7, 8);
	G.SSC();

	return 0;
}