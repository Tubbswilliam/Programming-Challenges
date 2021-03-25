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
/* function to print an array */
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