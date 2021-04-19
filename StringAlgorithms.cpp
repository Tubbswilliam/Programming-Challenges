//This file will contain the string manipulations and techniques
//Basic Algorithms(Sliding window,string hashing/Rplling hash) and Rabin-karp matching algorithm
//Intermediate algorithms(Prefix fn and KMP/Z-fn/Suffix array/Trie Ds)
//Advanced algorithms(Aho-Corasick/Suffix automation/Manacher's algorithm)

//1) Sliding window algorithm
//can be used to search for a certain pattern in a string.

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


	return 0;
}
