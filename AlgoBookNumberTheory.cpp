/*
//Checking if n is prime in 0(sqrt(n))
#include<bits/stdc++.h>
using namespace std;
bool prime(int n) {
	if (n < 2)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	cout << prime(n);
	return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;
vector<int> factor(int n) {
	vector<int>f;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			f.push_back(i);
			n /= i;
		}
	}
	if (n > 1)f.push_back(n);
	return f;
}

int main() {
	int n;
	cin >> n;
	vector<int>array = factor(n);
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
	return 0;
}