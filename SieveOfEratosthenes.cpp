//The time complexity for the sieve eratosthene algorithm is
//O(nlog(log(n)))
#include<bits/stdc++.h>
using namespace std;
int is_prime[100001];
void sieve() {
	int maxN = 10000;
	for (int i = 1; i <= maxN; i++)is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i  * i <= maxN; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= maxN; j += i)
				is_prime[j] = 0;
		}
	}
}
int main() {

	return 0;
}






