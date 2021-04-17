/*
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	if (b == 0)return a;
	else
		return gcd(b, a % b);
}

int lcm(int a, int b) {
	int product = a * b;
	return product / gcd(a, b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << "The gcd is: " << gcd(a, b) << endl;;
	cout << "The lcm is: " << lcm(a, b) << endl;

	return 0;
}
*/


#include<bits/stdc++.h>
using namespace std;
int pre[1000005], suff[1000005];
int arr[1000005];
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

int main() {
	int t, n, q, l, r;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		for (int i = 1; i <= n; i++)cin >> arr[i];

		pre[0] = suff[n + 1] = 0;
		for (int i = 1; i <= n; i++)pre[i] = gcd(arr[i], pre[i - 1]);

		for (int i = n; i >= 1; i--)suff[i] = gcd(arr[i], suff[i + 1]);

		while (q--) {
			cin >> l >> r;
			cout << gcd(pre[l - 1], suff[r + 1]) << endl;
		}
	}

	return 0;
}