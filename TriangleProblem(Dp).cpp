#Includde<bits\stdc++.h>
using namespace std;
/*The code below will basically calculate the minimum sum of a path in a triangle.
First i will use the recursive approach which has a higher time complexity of O(2**n)...
that is an exponential time complexity which is very slow.
->Next to improve on the approach we look at the Dp approach which wll slightly improve
the time cimplexity to O(n**2)...which is somehow faster but the space complexity is also n**2.
->To improve on the space complexity we will make use of arrays..that is a dp array and a previous array.
The space complexity is now improved to O(n) complexity*/

//First we will look at the brute force approach of recursion
int minPathSum(vector<vector>&triangle, int i = 0, int j = 0) {
	if (i == triangle.size() - 1)
		return triangle [i][j];
	else
		return triangle[i][j] + min(minPathSum(triangle, i + 1, j), minPathSum(triangle, i + 1), j + 1);
}

//Using dp
int minPathSum(vector<vector<int>>&triangle) {
	vector<vector<int>>dp;
	for (int i = 1; i <= triangle.size(); i++) {
		dp.push_back(vector<int>(i, 0));
	}
	int i = dp.size() - 1;
	while (i >= 0) {
		for (int j = o; j < dp[i].size(); j++) {
			if (i == triangle.size() - 1) {
				dp[i][j] = triangle[i][j];
			}
			else
				dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
		}
		i--;
	}
	return dp[0][0];
}

//Then we space optimize the dp solution above
int minPathSum(vector<vector<int>>triangle) {
	vector<int>dp(triangle.size(), 0);
	vector<int>previous_dp;
	int i = triangle.size() - 1;
	while (i >= 0) {
		for (int j = 0; j < dp.size(); j++) {
			if (i == triangle.size() - 1)
				dp[j] = trisngle[i][j];
			else
				dp[j] = triangle[i][j] + min(previous_dp[j], previous_dp[j + 1]);
		}
		previous_dp = dp;
		int newLengthDp = dp.size() - 1;
		dp = vector(newLengthDp, 0);
		i--;
	}

	return previous_dp[0];
}


int main() {


	return 0;
}