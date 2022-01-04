#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	} else if (n == 2 || n == 3) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}

	vector<ll>arr(n);
	int start = 2;
	for (ll i = 0; i < n / 2; i ++) {
		arr[i] = start;
		start += 2;
	}
	start = 1;
	for (ll i = n / 2; i < n; i ++) {
		arr[i] = start;
		start += 2;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}



	return 0;
}
