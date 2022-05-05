//depth first search algorithm

#include<bits/stdc++.h>
using namespace std;

const int n = 100005;
vector<int>adj[n];

bool visited[n];

void dfs(int current) {
	visited[current] = true;
	for (int i : adj[current]) {
		if (visited[i])continue;
		dfs(i);
	}
}


int main() {

	return 0;
}