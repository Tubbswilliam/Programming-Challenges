#Include<bits\stdc++.h>
using namespace std;
class Solution {
	//dfs helper function
	void dfs(vector<vector<char>>&grid, int row, int col, int rowNo, int colNo) {
		if (row < 0 || col < 0 || row >= rowNo || col >= colNo || grid[row][col] != '1')return;
		grid[row][col] = '2';
		dfs(grid, row - 1, col, rowNo, colNo);
		dfs(grid, row, col + 1, rowNo, colNo);
		dfs(grid, row + 1, col, rowNo, colNo);
		dfs(grid, row, col - 1, rowNo, colNo);

	}
public:
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		int rowNo = grid.size();
		int colNo = grid[0].size();
		if (rowNo == 0)return 0;
		for (int i = 0; i < rowNo; i++) {
			for (int j = 0; j < colNo; j++) {
				if (grid[i][j] == '1') {
					dfs(grid, i, j, rowNo, colNo);
					count += 1;
				}

			}
		}
		return count;
	}
};