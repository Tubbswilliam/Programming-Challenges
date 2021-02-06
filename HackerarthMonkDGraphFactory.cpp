/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, degree, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> degree;
		sum += degree;
	}
	if (sum == 2 * (n - 1))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}