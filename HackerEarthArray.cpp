/*
#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start,
                  int end)
{
	while (start < end)
	{
		swap(arr[start], arr[end]);
		start++;
		end--;
	}
}

/* Function to right rotate arr[]
of size n by d
void rightRotate(int arr[], int d, int n)
{
	reverseArray(arr, 0, n - 1);
	reverseArray(arr, 0, d - 1);
	reverseArray(arr, d, n - 1);
}
/* function to print an array
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
}

int main() {
	int A[] = {1, 2, 3, 4, 5, 6};

	int n = sizeof(A) / sizeof(A[0]);
	int k = 2;

	rightRotate(A, k, n);
	printArray(A, n);

	return 0;
}

*/

//The hackerEarth solution on Monk and Rotation
#include<bits/stdc++.h>
using namespace std;
void reverseArray(int arr[], int start,
                  int end)
{
	while (start < end)
	{
		swap(arr[start], arr[end]);
		start++;
		end--;
	}
}

/* Function to right rotate arr[]
of size n by d */
void rightRotate(int arr[], int d, int n)
{
	reverseArray(arr, 0, n - 1);
	reverseArray(arr, 0, d - 1);
	reverseArray(arr, d, n - 1);
}
/* function to print an array*/
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		int arr[n];
		for (int i = 0; i < n; i++) {
			arr[i];
		}
		rightRotate(arr, k, n);
		printArray(arr, n);
	}
	return 0;
}





//The main solution that i presented

#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, p;
		cin >> n;
		int arr[n];
		cin >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		k %= n;
		for (int i = 0; i < n; i++) {
			p = arr[(i + (n - k)) % n];
			cout << p << " ";
		}
		cout << "\n";

	}
	return 0;
}








