#include<bits/stdc++.h>
using namespace std;
int ExEA(int a, int b, int x, int y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = ExEA(b, a % b, x1; y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}
int main() {

	return 0;
}