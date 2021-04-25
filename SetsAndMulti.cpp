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

#include<bits/stdc++.h>
using namespace std;

int main() {
	unordered_set<int>s1;
	unordered_multiset<int>s2;
	s1.insert({1, 3, 4, 5, 53, 11, 22, 11, 22, 2, 1, 24, 5, 4});
	s2.insert({1, 3, 4, 5, 53, 11, 22, 11, 22, 2, 1, 24, 5, 4});
	for (auto i : s1) {
		cout << i << " ";
	}
	auto it = s1.find(4);
	cout << (*it) << endl;
	for (auto i : s2) {
		cout << i << " ";
	}
	unordered_multiset<string>s3;
	s3.insert({"abc", "william", "wwwwww"});
	cout << endl;
	for (auto i : s3) {
		cout << i << " ";
	}
	cout << endl;

	unordered_set<int>s4;
	s4.insert({s1, s2});
	for (auto i : s4) {
		cout << i << " ";
	}
	return 0;
}
