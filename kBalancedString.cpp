#include<bits/stdc++.h>
using namespace std;

int main() {
	long long t;
	cin >> t;
	while (t--) {
		int count = 0;
		long long n; cin >> n;
		long long k; cin >> k;
		string s;
		cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0')continue;
			if ((i + k < n and s[i + k] == '1') or (i - k >= 0 and s[i - k] == '1'))continue;
			if (i + k < n)
				s[i + k] = '1';
			else
				s[i] = '0';
			count++;
		}
		cout << count << endl;
	}

	return 0;
}