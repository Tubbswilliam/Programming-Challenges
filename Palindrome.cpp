/*
#include<bits/stdc++.h>
using namespace std;
//Checking if a word is a palindrome
void palindrome(string s) {
	int i = 0, j = s.length() - 1;
	while (i < j) {
		if (toupper(s[i]) != toupper(s[j])) {
			cout << "Not a palindrome" << endl;
		}
		else {
			i++, j--;
		}
	}
	cout << s << " - is a palindrome" << endl;
}
int main() {
	string s;
	cin >> s;
	palindrome(s);
	return 0;
}

*/

//Longest substring palindrome
#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
	if (s.length() <= 1)return s;
	int max_len = 1;
	int n = s.length();
	int st = 0, end = 0;

	//string with an odd length
	for (int i = 0; i < n - 1; i++) {
		int l = i, r = i;
		while (l >= 0 && r < n) {
			if (s[l] == s[r]) {
				l--, r++;
			} else {
				break;
			}
			int len = r - l - 1;
			if (len > max_len) {
				max_len = len;
				st = l + 1, end = r - 1;
			}
		}
	}
	//for the string with even length
	for (int i = 0; i < n - 1; i++) {
		int l = i, r = i + 1;
		while (l >= 0 && r < n) {
			if (s[l] == s[r]) {
				l--, r++;
			} else {
				break;
			}
			int len = r - l - 1;
			if (len > max_len) {
				max_len = len;
				st = l + 1, end = r - 1;
			}
		}
	}
	return s.substr(st, max_len);
}
int main() {
	string s;
	cin >> s;
	cout << longestPalindrome(s) << endl;

	return 0;
}