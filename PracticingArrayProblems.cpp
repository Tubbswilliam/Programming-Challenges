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
/*
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

*/

/*
//A pair with given sum
#include<bits/stdc++.h>
using namespace std;
bool hasPair(int arr[], int n, int sum) {
	sort(arr, arr + n);
	int l = 0, r = n - 1;

	while (l < r) {
		if (arr[l] + arr[r] == sum) {
			cout << "The positions of the two numbers are : ";
			cout << l << " " << r << endl;
			return true;
		}
		if (arr[l] + arr[r] < sum)
			l++;
		else if (arr[l] + arr[r] > sum)
			r--;
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	hasPair(arr, n, 11);


	return 0;
}

*/

//Finding a pair with a given sum in a rotated array
#include<bits/stdc++.h>
using namespace std;

bool hasPair(int arr[], int n, int sum) {
	//First we find the pivot point
	int i;
	for (i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1])
			break;
	}
	int l = (i + 1) % n; //l is always the smallest element
	int r = i; //r is always the largest element

	//Move either r or l till the meet.
	while (l != r) {
		if (arr[l] + arr[r] == sum) {
			cout << "The two positions are: ";
			cout << l << " and " << r << endl;
			return true;
		}
		if (arr[l] + arr[r] < sum)
			l = (l + 1) % n;
		else
			r = (n + r - 1) % n;
	}

	return false;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	hasPair(arr, n, 17);

	return 0;
}