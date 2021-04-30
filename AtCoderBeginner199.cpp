/*
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

*/
/*
//Intersection
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	int b[n];

	int biggest = -10000000;
	int smallest = 10000000;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		biggest = max(biggest, a[i]);
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < n; i++) {
		smallest = min(smallest, b[i]);

	}

	if ((smallest - biggest) + 1 < 0) {
		cout << 0 << endl;
	}
	else {cout << (smallest - biggest) + 1 << endl;}



	return 0;
}

*/


//RGB COLORING
#include<bits/stdc++.h>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	if (m == 0) {
		cout << 3 * pow(3, (m - 1)) << endl;
	} else {
		cout << 3 * pow(2, m - 2) << endl;//Not complete the proof does not hold
	}

	return 0;
}