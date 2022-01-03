#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector<ll>arr(n);
	ll diff = 0;
	for (ll i = 0; i < n; i++) {cin >> arr[i];}
	for (ll i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			diff += arr[i - 1] - arr[i];
			arr[i] += arr[i - 1] - arr[i];
		}
	}
	cout << diff;
	return 0;
}