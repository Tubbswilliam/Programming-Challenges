#include<bits\stdc++.h>
//Tarjan utilized the in/out time of a node
//to actually get each connceted component in a graph.
//He made use of a stack to store the visited array and i cause i'm more
//stupiiiiiddd i will use an array to track each acive node.
using namespace std;
vector<int>nodes[1001];
bool visited[1001], onStack[1001];
int in[1001], low[1001];
stack<int>st;
int timer = 1, SCC = 0;

void dfs(int node) {
	visited[node] = true;
	in[node] = low[node] = timer++;
	onStack[node] = true;
	st.push(node);

	for (int v : nodes[node]) {
		if ((visited[v] == true) && (onStack[v] == true))
			low[node] = min(low[node], in[v]);
		else {
			if (visited[v] == false) {
				dfs(v);
				if (onStack[v] == true)
					low[node] = min(low[node], low[v]);
			}
		}
	}
	if (in[node] == low[node]) {
		SCC++;
		cout << "SCC #" << SCC << endl;
		int v;
		while (1) {
			v = st.top();
			onStack[v] = false;
			cout << v << " ";
			if (v == node)break;

		}
		cout << endl;
	}
}


int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= m)
		cin >> a >> b, nodes[a].push_back(b);
	for (int i = 1; i <= n; i++)
		visited[i] = onStack[i] = false;
	for (int i = 1; i <= n; i++)
		if (visited[i] == false)dfs(i);


	return 0;
}
