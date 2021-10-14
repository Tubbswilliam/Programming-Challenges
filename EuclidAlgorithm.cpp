#include<bits/stdc++.h>
using namespace std;

pair<int, int>gcd(int a, int b) {
	if (b == 0)return {1, 0};
	pair<int, int>t = gcd(b, a % b);
	return{t.second, t.first - t.second*(a / b)};
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b).first << " " << gcd(a, b).second;
	return 0;
}