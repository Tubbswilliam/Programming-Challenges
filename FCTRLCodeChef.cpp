#include<bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int ZeroCount = 0;
		int c = 5;
		while ((n / c) > 0) {
			ZeroCount = ZeroCount + (n / c);
			c = c * 5;
		}
		cout << ZeroCount << endl;

	}
	return 0;
}