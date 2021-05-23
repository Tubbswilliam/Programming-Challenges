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