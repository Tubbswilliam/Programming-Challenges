
#include<bits/stdc++.h>
using namespace std;

template<class pair>
void print(const vector<pair>&v) {
	for (auto i : v) {cout << "(" << i.first << " , " << i.second << ")" << endl;}

}
int main() {
	pair<int, string>s(1, "william");
	cout << s.first << endl;
	cout << s.second << endl;
	cout << "#####################################" << endl;

	vector<pair<int, int>>v;
	v.push_back({21, 31});
	v.push_back(make_pair(34, 67));
	v.push_back(make_pair(22, 0));
	v.push_back(make_pair(30, 54));
	print(v);
	return 0;
}


