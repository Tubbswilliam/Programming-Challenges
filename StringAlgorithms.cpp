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