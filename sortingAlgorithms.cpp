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

//Inserion sort
void insertion(int arr[], int n) {
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}

}

void merge(int *a, int s, int e) {
	int mid = (s + e) / 2;

	int i = s;
	int j = mid + 1;
	int k = s;

	int temp[100];

	while (i <= mid && j <= e) {
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= e) {
		temp[k++] = a[j++];
	}
	//copy all elements to original array
	for (int i = s; i <= e; i++)
		a[i] = temp[i];
}

void mergesort(int a[], int s, int e) {
	//Base case
	if (s == e)return;
	//Follow the steps
	//1) Divide
	int mid = (s + e) / 2;

	//Recursively sort the arrays->s to mid and mid+1 to e
	mergesort(a, s, mid);
	mergesort(a, mid + 1, e);

	//merge the two parts
	merge(a, s, e);

}


int  main() {
	//Creating an array to sort;
	int arr[] = {98, 45, 23, 65, 78, 86, 20, 54, 10, 101};
	int n = sizeof(arr) / sizeof(arr[0]);
	//selectionsort(arr, n);
	//bubblesort(arr, n);
	//insertion(arr, n);
	mergesort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {cout << arr[i] << " ";}

	return 0;
}