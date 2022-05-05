//Breadth first search on shortest path

#include<bits/stdc++.h>
using namespace std;

void bfs() {
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[source] = 0;
	queue<int>q;
	q.push(source);
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i : adj[current]) {
			if (dist[i] == INF) {
				dist[i] = dist[current] + 1;
				q.push_back(i)
			}
		}

	}


}

int main() {

	return 0;
}