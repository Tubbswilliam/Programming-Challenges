#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0)return 0;
		int n = grid[0].size();
		if (n == 0)return 0;
		vector<vector<int>>paths(grid);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i - 1 >= 0 && j - 1 >= 0)
					paths[i][j] += min(paths[i - 1][j], paths[i][j - 1]);
				else {
					if (i - 1 >= 0)
						paths[i][j] += paths[i - 1][j];
					if (j - 1 >= 0)
						paths[i][j] += paths[i][j - 1];
				}
			}
		}
		return paths[m - 1][n - 1];
	}
};