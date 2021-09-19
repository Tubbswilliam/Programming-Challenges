#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
const int M = 1010;

int main() {
	int t;
	cin >> t;
	int n, m, a[N], b[M];
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		int suma = 0;
		int sumb = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			suma += a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
			sumb += b[i];
		}
		int ans = 0;
		while (suma <= sumb) {
			int mina = 100000000;
			int maxb = -1;
			int locmina = -1;
			int locmax = -1;
			for (int i = 0; i < n; i++) {
				if (a[i] < mina) {
					mina = a[i];
					locmina = i;
				}
			}
			for (int i = 0; i < m; i++) {
				if (b[i] > maxb) {
					maxb = b[i];
					locmax = i;
				}
			}
			if (mina >= maxb) {
				ans = -1;
				break;
			}
			ans++;
			swap(a[locmina], b[locmax]);
			suma -= mina;
			suma += maxb;

			sumb -= maxb;
			sumb += mina;
		}
		cout << ans << endl;
	}
	return 0;
}