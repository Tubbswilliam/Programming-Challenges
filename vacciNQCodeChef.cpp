#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, p, x, y;
		cin >> n >> p >> x >> y;
		int time = 0;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < p; i++) {
			if (arr[i] == 0)
				time += x;
			else
				time += y;
		}
		cout << time << endl;
	}

	return 0;
}


