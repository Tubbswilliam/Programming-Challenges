/*
#include<bits/stdc++.h>
using namespace std;

int main() {
	//largest element in array
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cout << arr[n - 1];
	return 0;
}

*/

//Function to left rotate an array one at a time

#include<bits/stdc++.h>
using namespace std;
void leftRotateOne(int arr[], int n) {
	int temp = arr[0];
	for (int i = 0; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = temp;
}

void rotatebyK(int arr[], int k, int n) {
	for (int i = 0; i < k; i++) {
		leftRotateOne(arr, n);
	}
}
void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int n, k;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//leftRotateOne(arr, n);
	rotatebyK(arr, 2, n);
	printArray(arr, n);

	return 0;
}