#include<bits/stdc++.h>
using namespace std;

//Naive Approach
int power(int base, int n) {
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res *= base;
	}
	return res;
}

int main() {
	int base, n;
	cin >> base >> n;
	cout << power(base, n) << endl;
	return 0;
}