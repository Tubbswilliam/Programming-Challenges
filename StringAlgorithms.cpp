//This file will contain the string manipulations and techniques
//Basic Algorithms(Sliding window,string hashing/Rplling hash) and Rabin-karp matching algorithm
//Intermediate algorithms(Prefix fn and KMP/Z-fn/Suffix array/Trie Ds)
//Advanced algorithms(Aho-Corasick/Suffix automation/Manacher's algorithm)

//1) Sliding window algorithm
//can be used to search for a certain pattern in a string.
/*
#include<bits/stdc++.h>
using namespace std;
string text, pattern;
int txt, pn;

bool match(int left, int right) {
	for (int i = 0; i < pn; i++) {
		if (text[left + i] != pattern[i])return false;
	}
	return true;

}

int main() {
	getline(cin, text);
	getline(cin, pattern);

	txt = text.size();
	pn = pattern.size();

	for (int left = 0, right = pn - 1; right < txt; left++, right++)
		if (match(left, right))
			cout << left << " " << right << endl;

	cout << "No";


	return 0;
}
*/

//question from HackerEarth
/*
You are given a substring " to the " ,
your task is to check whether this substring is present in
the input string or not. If present print "YES" otherwise print "NO".

#include<bits/stdc++.h>
using namespace std;
string text, pattern;
int txt, pn;

bool match(int left, int right) {
	for (int i = 0; i < pn; i++) {
		if (text[left + i] != pattern[i])return false;
	}
	return true;

}

int main() {
	getline(cin, text);
	pattern = "to the";

	txt = text.size();
	pn = pattern.size();

	for (int left = 0, right = pn - 1; right < txt; left++, right++)
		if (match(left, right)) {
			cout <<  "YES" << endl;
			break;
		}

		else {
			cout << "NO" << endl;
			break;
		}


	return 0;
}
*/

/*
//String hashing helps improve the time complexity of two string of equal length to O(1)
//concepts like collision,string->hash function->hash value
//we can simply just compare their hash values
// The hash function must generate the same hash value if the same string
//is passed again.

//Polynomial rolling hashing is used to convert the strings into their respective hash values.
//Summation s[i]*p^(i) mod m is the polynomial hash function
//p is a prime number
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long gethash(string text) {
	long long value = 0;
	long long prime = 31;
	long long prime_power = 1;
	for (char ch : text) {
		value = (value + (ch - 'a' + 1) * prime_power) % mod;
		prime_power = (prime_power * prime) % mod;
	}
	return value;
}
int main() {
	int flag = 1;
	while (flag) {
		string text;
		cin >> text;

		if (text == ".") {
			flag = false;

		}
		else {
			cout << "key: " << text << "Hash: " << gethash(text) << endl;

		}
	}

	return 0;
}

*/

//Substrings hashing
//In this case we will make use of the prefix arrays to store the hash upto i
//Calculate the hash value of thesubstring by taking the dp[r]-dp[l-1]/p^l

#include<bits/stdc++.h>
using namespace std;
#define mod 100000007;
long long dp[10000001];
long long inv[10000001];

long long power(long long a, long long n) {
	long long result = 1;
	while (n) {
		if (n$1)result = (result * a) % mod;
		n >>= 1;
		a = (a * a) % mod;
	}
	return result;
}
void init(string text) {
	long long prime = 31;
	long long prime_power = 1;
	dp[0] = (text[0] - 'a' + 1);

	for (int i = 1; i < text.size(); i++) {
		char ch = text[i];

		prime_power = (prime_power * prime) % mod;
		inv[i] = power(prime_power, mod - 2);

		dp[i] = (dp[i - 1] + (ch - 'a' + 1) * prime_power) % mod;
	}
}

long long substringHash(int L, int R) {
	int result = dp[R];
	if (L > 0)result -= dp[L - 1];
	result = (resut * inv[L]) % mod;

	return result;
}

int main() {
	string test;
	int t, L, R;
	cin >> text;
	init(text);

	cin >> t;
	while (t--) {
		cin >> L >> R;
		cout << substringHash(L, R) << endl;
	}
	return 0;
}