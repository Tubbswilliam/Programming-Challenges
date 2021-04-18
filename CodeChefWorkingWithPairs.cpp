/*
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


*/




#include<bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int>&a, const pair<int, int>&b) {
	if (a.first == b.second)return a.second > b.second;
	return a.first < b.first;
}
double round(double ans, int x) {
	double mul = pow(10, x);
	return round(ans * mul) / mul;
}
void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	//sort the vector as required
	sort(v.begin(), v.end(), comp);
	//Calculate the distance
	double ans = 0.00;
	for (int i = 1; i < n; i++) {
		ans += sqrt(((v[i].first - v[i - 1].first) * (v[i].first - v[i - 1].first))
		            + ((v[i].second - v[i - 1].second) * (v[i].second - v[i - 1].second))
		           );
	}
	//cout << ans << endl;
	cout << round(ans, 2) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
