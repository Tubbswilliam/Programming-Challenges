#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 0)cout << 1;
	int comp = 0;
	int ind = 0;
	while (n > 0) {
		if (!(n & 1)) {
			comp = comp | (1 << ind);
		}
		n = n >> 1;
		ind++;
	}
	cout << comp;
	return 0;
}