#include<bits/stdc++.h>
using nmaespace std;


int main() {
	int n;
	cin >> n;
	int dp[n + 1];
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i < j)continue;
			dp[i] = dp[i - j];
		}
	}
	return 0;
}