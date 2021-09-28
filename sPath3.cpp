#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long t;
	cin >> t;
	while (t--) {
		long long n, m, x, y;
		cin >> n >> m >> x >> y;
		if (n > m)swap(n, m);
		long long diff = m - n;

		long long case1 = x * (n + m - 2); //y>2*x
		long long case2 = (y * (n - 1)) + (diff * x); //y>x
		long long case3 = (y * (n - 1)) + ((diff / 2) * 2) * y + (diff % 2) * x;

		long long ans = min({case1, case2, case3});
		cout << ans << "\n";

	}

	return 0;
}