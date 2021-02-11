#include<bits\stdc++.h>
using namespace std;
// Complete this function
void quickSort(vector <int> &arr) {
	int n = arr.size();
	if (n < 2)
		return;

	vector <int> left;
	vector <int> right;

	int pivot = arr[0];

	for (int i = 1; i < n; ++i) {
		if (arr[i] <= pivot) {
			left.push_back(arr[i]);
		}
		else {
			right.push_back(arr[i]);
		}
	}
	quickSort(left);
	quickSort(right);

	int index = 0;

// Copy left side back in the original array
	for (unsigned int l = 0; l < left.size(); ++l) {
		arr[index++] = left[l];
		cout << left[l] << " ";
	}

// put the pivot between left & right arrays
	arr[index++] = pivot;
	cout << pivot << " ";

// Copy right side in the original array
	for (unsigned int r = 0; r < rightArray.size(); ++r) {
		arr[index++] = rightArray[r];
		cout << rightArray[r] << " ";
	}
	cout << endl;
}
int main() {
	return 0;
}