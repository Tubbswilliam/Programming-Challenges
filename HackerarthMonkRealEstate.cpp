/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000001];
int main() {
	int t, e, x, y;
	set<int>s;
	cin >> t;
	while (t--) {
		cin >> e;
		for (int i = 1; i <= e; i++) {
			cin >> x >> y;
			s.insert(x);
			s.insert(y);
		}
		cout << s.size() << endl;
		s.clear();
	}
	return 0;
}