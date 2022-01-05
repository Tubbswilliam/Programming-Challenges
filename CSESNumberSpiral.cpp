#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll t, x, y;
	cin >> t;
	while (t--) {
		cin >> y >> x;
		if (x > y) {
			if (x % 2 == 1) {
				cout << x*x - y + 1 << endl;
			} else {
				x--;
				cout << x*x + y << endl;
			}

		}
		else {
			if (y % 2 == 0) {
				cout << y*y - x + 1 << endl;
			}
			else {
				y--;
				cout << y*y + x << endl;
			}
		}
	}
	return 0;
}