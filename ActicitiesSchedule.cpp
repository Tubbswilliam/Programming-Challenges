#include<bits/stdc++.h>
using namespace std;
bool comp(vector<int>&a, vector<int>&b) {
	return a[1] < b[1];
}

int main() {
	vector<vector<int>>activities = {{4, 6}, {3, 7}, {5, 8}, {7, 10}, {13, 15}, {4, 10}};
	sort(activities.begin(), activities.end(), comp);
	for (int i = 0; i < activities.size(); i++) {
		cout << activities[i][0] << " " << activities[i][1] << "\n";
	}

	int ans = 0;
	int free = 0;
	for (int i = 0; i < activities.size(); i++) {
		if (free <= activities[i][0]) {
			ans++;
			free = activities[i][1];
		}
	}
	cout << ans;
}