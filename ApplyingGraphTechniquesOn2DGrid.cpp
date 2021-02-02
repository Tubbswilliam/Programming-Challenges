#include<bits\stdc++.h>
using namespace std;
bool visited[1001][1001];
int N, M;

bool isValid(int x, int y) {
	if (x < 0 || y < 0 || x > N || y > M)return false;
	if (visited[x][y] == true)return false;
	return true;
}

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
	visited[x][y] = 1;
	cout << x << " " << y << endl;

	for (int i = 1; i <= 4; i++) {
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
	dfs(1, 1);

	return 0;
}