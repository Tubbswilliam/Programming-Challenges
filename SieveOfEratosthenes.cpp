/*
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
*/


//Spoj...Kth prime number given a query
#include<bits/stdc++.h>
using namespace std;
vector<int>primes;
bool ar[900000001];
void sieve() {
	int maxN = 90000000;
	ar[0] = ar[1] = true;
	for (int i = 2; i * i <= maxN; i++) {
		if (!ar[i]) {
			for (int j = i * i; j <= maxN; j += i)
				ar[j] = true;
		}
	}
	for (int i = 2; i <= maxN; i++) {
		if (!ar[i])
			primes.push_back(i);
	}
}
int main() {
	int n, q;
	cin >> q;
	sieve();
	while (q--) {
		cin >> n;
		cout << primes[n - 1] << endl;
	}
	return 0;

}




