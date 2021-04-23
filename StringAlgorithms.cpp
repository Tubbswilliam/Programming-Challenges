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

*

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

*/



/*
//Spoj Problem
Write a program that finds all
occurences of a given pattern in a given input string. This is often referred to as finding a needle in a haystack.

The program has to detect all occurences of the needle in the haystack.
 It should take the needle and the haystack as input,
 and output the positions of each occurence, as shown below. The suggested
implementation is the KMP algorithm, but this is not a requirement. However, a naive approach will probably exceed the time limit, whereas other algorithms are more complicated... The choice is yours.
*/


/*
//We can use the rabin-Karp algorithm to find all the occurrences of a
//certain pattern in a word.


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define prime 119
//Function to calculate the hashValues
ll hashValue(string text, int n) {
	ll result = 0;
	for (int i = 0; i < n; i++) {
		result += ((ll)text[i] * (ll)pow(prime, i));
	}
	return result;
}

//Recalculate hash value when rolling or moving the window
ll calculatenewHash(string text, int oldIndex, int newIndex, ll oldHash, int patlength) {
	ll newHash = oldHash - text[oldIndex];
	newHash /= prime;
	newHash += (ll)(text[newIndex] * (ll)pow(prime, patlength - 1));
	return newHash;
}

//Check equal
bool checkEqual(string s1, string s2, int start1, int e1, int start2, int e2) {
	if (e1 - start1 != e2 - start2)return false;
	while (start1 <= e1 and start2 <= e2) {
		if (s1[start1] != s2[start2])return false;
		start1++;
		start2++;
	}
	return true;
}

int main() {
	string str = "ababcabdab";
	string pattern = "abd";

	ll patterHash = hashValue(pattern, pattern.length());
	ll strHash = hashValue(str, pattern.length());

	for (int i = 0; i <= str.length() - pattern.length(); i++) {
		if (patterHash == strHash and
		        checkEqual(str, pattern, i, i + pattern.length() - 1, 0, pattern.length() - 1))
			cout << i << endl;
		if (i < str.length() - pattern.length()) {
			strHash = calculatenewHash(str, i, i + pattern.length(), strHash, pattern.length());
		}
	}

	return 0;
}


*/

//Knut-morris-Pratt Algorithm
//it completely depends on the prefix and suffix functions
//The longest prefix array(knowledge centre)
#include<bits/stdc++.h>
using namespace std;

void kmp(string text, string pattern) {
	//Building the longest prefix suffix array(lps)
	int m = pattern.length(), n = text.length();
	vector<int>lps(m, 0);
	for (int i = 1; i < m; i++) {
		int j = lps[i - 1];
		while (j > 0 && pattern[i] != pattern[j])j = lps[j - 1];
		if (pattern[i] == pattern[j])j++;
		lps[i] = j;
	}
}

/*
//Z algorithm
//This algorithm is used to find the longest substring at k which is
//also the prefix of the string.

#include<bits/stdc++.h>
using namespace std;
int z[1000];

void z_function(string s) {
	int n = s.size();
	z[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (s[j - i] == s[j]) {
				z[i]++;
			}
			else {
				break;
			}
		}
	}


}


int main() {

	return 0;
}



//Right most segment match[L,R]
*/