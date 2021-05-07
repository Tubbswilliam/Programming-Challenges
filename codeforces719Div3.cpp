
//This Round was just a practice round for me
//Problem A- Do Not be distracted
/*
#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	string sorted = s;
	sort(sorted.begin(), sorted.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
	if (s.length() == sorted.length())
		cout << "YES" << endl;
	else
		cout << "NO" << '\n';
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
	int t;
	cin >> t;
	while (t--) {
		solve();
	}




	return 0;
}

*/

//Problem c:Not adjacent Matrix
#include<bits/stdc++.h>
using namespace std;

void solve() {
	int current = 1;
	int n;
	cin >> n;
	if (n == 2)cout << "-1" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << current << " " << endl;
			current += 2;
			if (current > n * n)
				current = 2;
		}
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
	int t;
	cin >> t;
	while (t--) {
		solve();
	}




	return 0;
}
