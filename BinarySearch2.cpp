#include<bits/stdc++.h>
using namespace std;
/*
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

*/

//Binary Search O(log n)

bool Binarysearch() {
	int array[10] = {1, 23, 24, 34, 45, 100, 10000, 99, 20, 50};
	int target = 34;
	int f = 0;
	int l = 9;
	sort(array, array + 10);
	while (f < l) {
		int mid = f + (l - f) / 2;
		if (array[mid] == target) {return true;}
		else if (array[mid] < target) {f = (mid + 1);}
		else {l = (mid - 1);}
	}
	return false;
}

int main() {
	cout << boolalpha << Binarysearch() << endl;
	return 0;
}
