#include<bits/stdc++.h>
using namespace std;

int main() {
	long long t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		long long num;
		long long sum_A = 0;
		long long sum_B = 0;
		for (int i = 0; i < n; i++) {
			cin >> num;
			sum_A += num * i;
		}
		for (int i = 0; i < n; i++) {
			cin >> num;
			sum_B += num * i;
		}
		cout << sum_B - sum_A << endl;
	}

	return 0;
}