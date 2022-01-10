#include<bits/stdc++.h>
#define ll long long

using namespace std;

int numPairDivisibleBy60(vector<int>time) {
	vector<int>mp(60, 0);
	int cntpair = 0;
	for (auto it : time) {
		int num = it % 60;
		if (num == 0)cntpair += mp[0];
		cntpair += mp[60 - num];
		mp[num]++;
	}
	return cntpair;
}
int main() {
	int n;
	cin >> n;
	vector<int>time(n);
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}
	cout << numPairDivisibleBy60(time);
	return 0;
}