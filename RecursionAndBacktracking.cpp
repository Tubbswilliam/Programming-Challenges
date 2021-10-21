#include<bits/stdc++.h>
using namespace std;

int fun(long long arr[], long long s1, long long s2, int i, int n) {
	if (i == n)return abs(s1 - s2);
	long long left = fun(arr, s1 + arr[i], s2, i + 1, n);
	long long right = fun(arr, s1, s2 + arr[i], i + 1, n);
	return min(left, right);

}

int main() {
	int n;
	cin >> n;

	long long arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << fun(arr, arr[0], 0, 1, n);

	return 0;
}