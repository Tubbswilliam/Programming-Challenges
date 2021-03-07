/*Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxPower(string s) {
		int count = 1, max_count = 1;
		char prev = s[0];
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == prev) {
				count++;
				max_count = max(max_count, count);
			}
			else {
				count = 1;
				prev = s[i];
			}
		}
		return max_count;
	}
};
int main() {return 0;}