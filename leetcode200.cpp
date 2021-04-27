/*
Number of Islands


Given an m x n 2D binary grid grid which represents a map of '1's (land)
and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent
lands horizontally or vertically. You may assume all four edges of the
grid are all surrounded by water.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<char>>& grid, int i, int j) {
		grid[i][j] = '0';

		if (i + 1 < grid.size() && grid[i + 1][j] == '1')
			dfs(grid, i + 1, j);
		if (i - 1 >= 0 && grid[i - 1][j] == '1')
			dfs(grid, i - 1, j);
		if (j + 1 < grid[0].size() && grid[i][j + 1] == '1')
			dfs(grid, i, j + 1);
		if (j - 1 >= 0 && grid[i][j - 1] == '1')
			dfs(grid, i, j - 1);
	}

	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int count = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
					dfs(grid, i, j);
					count++;
				}

			}
		}
		return count;
	}
};

int main() {
#ifndef ONLINE_JUDGE
//for getting input from input.txt
	freopen("inputBFSandDFS.txt", "r", stdin);
// for writing output to output.txt
	freopen("outputBFSandDFS.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);



	return 0;
}