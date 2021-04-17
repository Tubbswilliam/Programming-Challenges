//sets and multiSets operations
#include<bits/stdc++.h>
using namespace std;

int main() {
	set<int>s1;
	s1.insert(5);
	s1.insert(1);
	s1.insert(4);
	s1.insert(3);
	s1.insert(15);
	for (auto i : s1)cout << i << " " << endl;
	s1.erase(15);
	for (auto i : s1)cout << i << " " << endl;
	auto it = s1.find(4);
	s1.erase(s1.begin(), it);
	cout << "//////////////////////////" << endl;
	for (auto i : s1)cout << i << " " << endl;

	set<pair<int, int>>s2;
	s2.insert({12, 34});
	s2.insert({1, 4});
	s2.insert({2, 40});
	for (auto i : s2)cout << i.first << " " << i.second << endl;
	return 0;
}