//Upper_bound
//lower_bound
//Binary search

#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int>ar = {1, 1, 2, 2, 2, 4, 7, 10};
	int br[] = {2, 3, 5, 7};

	cout << binary_search(ar.begin(), ar.end(), 3) << endl;
	cout << binary_search(br, br + 4, 5) << endl;

	cout << *upper_bound(ar.begin(), ar.end(), 2) << endl;
	cout << *upper_bound(br, br + 4, 5) << endl;

	cout << *lower_bound(ar.begin(), ar.end(), 2) << endl;
	return 0;
}