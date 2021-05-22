#include<bits/stdc++.h>
using namespace std;

void solve() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int val = 1;
		n /= 2;
		while (n > 0) {
			n /= 2;
			val *= 2;
		}
		val--;
		cout << val << "\n";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();


	return 0;
}