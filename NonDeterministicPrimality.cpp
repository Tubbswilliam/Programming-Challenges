#include<bits/stdc++.h>
using namespace std;
//Fermat's Primality test
long long mulmod(long long a, long long b, long long c) {
	long long x = 0, y = a % c;
	while (b > 0) {
		if (b % 2 == 1) {
			x = (x + y) % c;
		}
		y = (y * 2LL) % c;
		b /= 2;
	}
	return x % c;
}

long long binPower(long long a, long long n, long long mod) {
	long long res = 1;
	while (n) {
		if (n & 1)
			res = mulmod(res, a, mod);
		n >>= 1;
		a = mulmod(a, a, mod);
	}
	return res % mod;
}

bool isPrime(int n, int iter = 5) {
	if (n <= 4)return n == 2 || n == 3;
	for (int i = 1; i <= iter; i++) {
		long long a = 2 + rand() % (n - 3);
		long long res = binPower(a, n - 1, n);

		if (res != 1)return false;
	}
	return true;
}
int main() {
	long long t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (isPrime(n))cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}