//Binomial coefficient

#include<bits/stdc++.h>
using namespace std;

int binomialCoefficient(int n, int k) {
	int ans = 1;


	if (k > n - k) {
		k = n - k;
	}
	for (int i = 0; i < k; i++) {
		ans *= (n - i);
		ans /= (i + 1);
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << binomialCoefficient(n, k);
	return 0;
}