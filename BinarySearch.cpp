#include<bits/stdc++.h>
using namespace std;

//BASIC Linear Search O(n)
int main() {
	int nstrings = 5;
	int array[nstrings] = {1, 23, 24, 34, 45};

	int target = 34;
	for (int i = 0; i < nstrings; i++) {
		if (array[i] == target) {
			cout << "YES" << endl;
			//break;
		}
		else
			cout << "NO" << endl;
	}

	return 0;
}


