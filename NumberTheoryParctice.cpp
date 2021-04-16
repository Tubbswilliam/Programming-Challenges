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