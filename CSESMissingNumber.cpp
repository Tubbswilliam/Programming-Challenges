#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	vector<ll>arr(n);
	ll sum = 0;
	ll numcount = n * (n + 1) / 2;
	for (ll i = 0; i < n - 1; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	cout << numcount - sum;

	return 0;
}