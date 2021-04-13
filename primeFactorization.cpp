//The time complexity of the code below is O(log n)
//Although if n is prime it is the worst case
//where it becomes O(n);
#include<bits/stdc++.h>
using namespace std;
void primeFact(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0)
				cnt++, n /= i;
			cout << i << "i" << cnt << endl;
		}
	}
}

int main() {
	int n;
	cin >> n;
	primeFact(n);
	return 0;
}

