#include<bits\stdc++.h>
using namespace std;
// Complete the quickSort function below.
vector<int> quickSort(vector<int> arr) {
	int n = arr.size();
	int pivot = arr[0];
	for (int i = 1; i < n; i++) {
		if (pivot > arr[i]) {
			for (int j = i; j > 0; j--) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
	return arr;
}

int main() {
	return 0;
}