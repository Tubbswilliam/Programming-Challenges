#include<bits/stdc++.h>
using namespace std;

bool palindrome(int i, string word) {
	if (i >= word.length() / 2)return true;
	if (word[i] != word[word.length() - i - 1])return false;

	return palindrome(i + 1, word);
}

int main() {
	string word;
	cin >> word;
	cout << std::boolalpha << palindrome(0, word);

	return 0;
}