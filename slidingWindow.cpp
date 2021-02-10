//Finding the maximum sum of k-elements in an array
#include<bits\stdc++.h>
using namespace std;
//Steps using sliding window.
//First we create the window then slide it over the elements in the array.
int max_sum(int arr[], int n, int k) {
	//compute for the first window
	int maxsum = 0;
	for (int i = 0; i < k; i++) {
		maxsum += arr[i];
	}
	//Calculate the sum of the remaining window by removing the 1st element
	//of the previous window then adding the new element
	int window_sum = maxsum;
	for (int i = k; i < n; i++) {
		window_sum += arr[i] - arr[i - k];
		maxsum = max(maxsum, window_sum);
	}
	return maxsum;
}
int main() {
	//Lets test
	int arr[] = { 1, 300, 2, 10, 200, 3, 1, 90, 20 };
	int k = 3;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << max_sum(arr, n, k);
	return 0;
}