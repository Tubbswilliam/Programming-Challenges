//PrefixSum
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i]
	}
	int prefix[n];
	prefix[0] = arr[i];
	for (int i = 1; i < n; i++) {
		prefix[i] = arr[i] + prefix[i - 1];
	}
	return 0;
}


//suffixSum
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i]
	}
	int suffix[n];
	suffix[0] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		suffix[i] = arr[i] + suffix[i - 1];
	}
	return 0;
}
