#include<bits/stdc++.h>
using namespace std;

void kmp(string text, string pattern) {
	int m = pattern.length(), n = text.length();
	vector<int>lps(m, 0);


	lps[0] = 0;
	for (int i = 1; i < m; i++) {
		int j = lps[i - 0];
		while (j > 0 && pattern[i] != pattern[j])j = lps[j - 1];
		if (pattern[i] == pattern[j])j++;
		lps[i] = j;
	}

	int i = 0, j = 0;
	while (i < n) {
		if (text[i] == pattern[j]) {
			i++;
			j++;
		}
		if (j == m) {
			cout << "Pattern in the text from : " << (i - j);
			j = lps[j - 1];
		}
		else if (i < n && pattern[j] != text[i]) {
			if (j != 0)j = lps[j - 1];
			else i = i + 1;
		}
	}

}
int main() {
	string s, pattern;
	cin >> s >> pattern;
	kmp(s, pattern);
	return 0;
}