#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int arr[6];
		for (int i = 0; i < 6; i++) {
			cin >> arr[i];
		}
		//for (int i = 0; i < 6; i++) {
		//	cout << arr[i] << " ";
		//}
		int f = 0;
		int s = 0;
		for (int i = 0; i < 6; i += 2) {
			f += arr[i];
		}
		for (int i = 1; i < 6; i += 2) {
			s += arr[i];
		}
		//cout << f << endl;
		//cout << s << endl;
		if (f < s)
			cout << 2 << endl;
		else
			cout << 1 << endl;
	}
	return 0;
}