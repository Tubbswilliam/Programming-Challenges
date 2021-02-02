#include<bits\stdc++.h>
/*Below code is topological sorting algorithm using the Kahn's Algorithm
If you stupid like me hahahaha Yuh will realize it's somehow similar to BFS...But Not BFS lol
But keenly you will realize we are using the indegree of a not to sort them. */
using namespace std;
Vector<int>nodes[100];
int result[], in[100];

void kahn(int n) {
	queue<int>Q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)
			Q.push(i);
	}
	while (!Q.empty()) {
		int curr = Q.front();
		result.push_back(curr);
		Q.pop();

		for (int v : nodes[curr]) {
			in[v]--;
			if (in[v] == 0)
				Q.push(v);
		}
	}
	cout << "Topological sort : ";
	for (int node : res)
		cout << node << " ";

}
int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= m, i++) {
		cin >> a >> b;
		nodes[a].push_back(b);
		in[b]++;
	}
	kahn(n);

	return 0;
}