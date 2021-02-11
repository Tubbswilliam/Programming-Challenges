//A. Young Physicist
#include<bits\stdc++.h>
using namespace std;
int main() {
	int t, sx = 0, sy = 0, sz = 0, x, y, z;
	cin >> t;
	while (t--) {
		cin >> x >> y >> z;
		sx += x;
		sy += y;
		sz += z;
	}
	if (sx == 0 && sy == 0 && sz == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}