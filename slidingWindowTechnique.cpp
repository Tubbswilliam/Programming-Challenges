#include<bits/stdc++.h>
using namespace std;

//Naive solution
void printMax(int arr[], int n, int k) {
	for (int i = 0; i <= n - k; i++) {
		int max = arr[i];
		for (int j = 1; j < k; j++) {
			if (arr[i + 1] > max) {
				max = arr[i + j];
			}
		}
	}
	cout << max << " ";
}

int main() {

	return 0;
}
