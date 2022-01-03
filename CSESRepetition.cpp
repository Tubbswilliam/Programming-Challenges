#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	string s;
	cin >> s;
	ll best = 0;
	ll count = 0;
	char prev;
	for (ll i = 0; i < s.length(); i++) {
		if (s[i] != prev) {
			best = max(count, best);
			count = 1;
		}
		else {
			count++;
		}
		prev = s[i];
	}
	best = max(count, best);
	cout << best;
	return 0;
}