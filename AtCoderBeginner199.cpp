//Square Inequality
#include<bits/stdc++.h>
using namespace std;
void solve(int a, int b, int c) {
	if (((a * a ) + (b * b) ) < c * c)
		cout << "Yes" << endl;
	else {
		cout << "No" << endl;
	}
}

int main() {
// #ifndef ONLINE_JUDGE
// 	//for getting input from input.txt
// 	freopen("input.txt", "r", stdin);
// 	// for writing output to output.txt
// 	freopen("output.txt", "w", stdout);
// #endif
	int a, b, c;
	cin >> a >> b >> c;
	solve(a, b, c);

	return 0;
}



