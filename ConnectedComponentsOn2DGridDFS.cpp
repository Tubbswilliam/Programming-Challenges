#include<bits\stdc++.h>
using namwspace std;
/*In this section we try counting the number of connected components on a 2D grid using DFS*/
int ar[1001][1001];
bool visited[1001][1001];
int N, M;

bool isValid(int x, int y) {
	if (x < 0 || y < 0 || x > N || y > M)return false;
	if (visited[x][y] == true || ar[x][y] == 0)return false;
	return true;
}

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		if (isValid(x + dx[i], y + dy[i])) {
			dfs(x + dx[i], y + dy[i]);
		}
	}

}



int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> ar[i][j];
		}
	int connectedComponents = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			if (visited[i][j] == 0 && ar[i][j] == 1)
				dfs(i, j), connectedComponents++;
	}
	cout << "connected Components = " << connectedComponents << endl;

	return 0;
}