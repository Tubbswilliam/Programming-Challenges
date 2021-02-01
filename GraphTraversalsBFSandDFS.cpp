#include<bits\stdc++.h>
using namespace std;
enum states {Unvisited, Instack, Visited};
class Graph {
	int m_v;
	int time;
	vector<vector<int>>m_adj;
	bool DFS_rec(int s, vector<states>&visited) {
		visited[s] = Instack;
		//pre[s] = time++;
		//cout << s << endl;
		for (auto u : m_adj[s]) {
			if (visited[u] == Instack)return true;
			if (visited[u] == Unvisited && DFS_rec(u, visited)) return true;
			//DFS_rec(u, visited, pre, post);			}
		}
		visited[s] = Visited;
		return false;
		// post[s] = time++;
	}
	void DFS_iter(int s, vector<bool>&visited) {
		stack<int>S;
		S.push(s);
		visited[s] = true;
		while (!S.empty()) {
			int u = S.top();
			S.pop();
			cout << u << endl;
			for (int v : m_adj[u]) {
				if (!visited[v]) {
					S.push(v);
					visited[v] = true;
				}
			}
		}

	}
public:
	Graph(int v): m_v(v), m_adj(v), time(0) {}
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
	bool hasCycle() {
		vector<states>visited(m_v, Unvisited);
		//vector<int>pre(m_v), post(m_v);
		for (int i = 0; i < m_v; i++) {
			if (visited[i] == Unvisited && DFS_rec(i, visited)) {
				//DFS_rec(i, visited, pre, post);
				return true;
			}
		}
		return false;
		// for (int i = 0; i < m_v; i++) {
		// 	cout << i << " : " << pre[i] << " --" << post[i] << endl;
		// }
	}
};
int main() {
// #ifndef ONLINE_JUDGE
// 	//for getting input from input.txt
// 	freopen("inputBFSandDFS.txt", "r", stdin);
// 	// for writing output to output.txt
//	freopen("outputBFSandDFS.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Graph G(5);
	G.addEdge(0, 1);
	G.addEdge(0, 3);
	G.addEdge(1, 2);
	G.addEdge(3, 4);
	G.addEdge(4, 0);
	//G.BFS(0);
	//G.DFS();
	bool hasCycle = G.hasCycle();
	cout << boolalpha << hasCycle << endl;


	return 0;
}

