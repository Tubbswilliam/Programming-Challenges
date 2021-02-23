//Implememnting the sorting algorithms
#include<bits/stdc++.h>
using namespace std;

//Selection sort
void selectionsort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int imin = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[imin])
				imin = j;
		}
		int temp = arr[i];
		arr[i] = arr[imin];
		arr[imin] = temp;
	}

}

//Bubble sort Algorithms
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubblesort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

int  main() {
	//Creating an array to sort;
	int arr[] = {98, 45, 23, 65, 78, 86, 20, 54, 10, 101};
	int n = sizeof(arr) / sizeof(arr[0]);
	//selectionsort(arr, n);
	//bubblesort(arr, n);
	for (int i = 0; i < n; i++) {cout << arr[i] << " ";}

	return 0;
}