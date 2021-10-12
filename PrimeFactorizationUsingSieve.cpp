#include<bits/stdc++.h>
using namspace std;
int ar[1000000];
void sieve() {
	int maxn = 100000;
	for (int i = 1; i <= maxn; i++) {
		if (ar[i] == -1) {
			for (int j = i * i; j <= maxn; j += i) {
				if (ar[j] == -1)
					ar[j] = i;
			}
		}
	}
}
int main() {

	return 0;
}