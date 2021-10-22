#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int arr[4];
		map<int, int>mapset;
		for (int i = 0; i < 4; i++) {
			cin >> arr[i];
			mapset[arr[i]]++;
		}
		if (mapset.size() == 3 || mapset.size() == 4)cout << 2 << "\n";
		else if (mapset.size() == 1)cout << 0 << "\n";
		else if (mapset[arr[0]] == 2)cout << 2 << "\n";
		else cout << 1 << "\n";
	}

	return 0;
}