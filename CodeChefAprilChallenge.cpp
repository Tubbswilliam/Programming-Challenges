/*
//Problem 1 on valid pair
#include<bits/stdc++.h>
using namespace std;
void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b || a == c || b == c)cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {

	solve();
	return 0;
}


/*
//problem 2 on World Record
#include<bits/stdc++.h>
using namespace std;

double round(double x, int y) {
	double mul = pow(10, y);
	return round(x * mul) / (mul);
}

void solve() {
	double k1, k2, k3, v;
	cin >> k1 >> k2 >> k3 >> v;
	double timetaken = round(100 / (k1 * k2 * k3 * v), 2);
	if (timetaken < 9.58) cout << "YES" << endl;
	else cout << "NO" << endl;

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;
void solve(int n, int k) {
	int count = 1;
	vector<string>s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] == s[j])count++;
		}
	}
	if (k == 1)cout << "NO" << endl;
	else if (count >= k)cout << "YES" << endl;
	else cout << "NO" << endl;

}

int main() {
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		solve(n, k);

	}
}