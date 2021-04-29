//Fenwick Tree

#include<bits/stdc++.h>
using namespace std;

int fen[N];

void update(int i, int val) {
	while (i < N) {
		//val is the value to be added or updated
		fen[i] += val;
		i += i + (i & (-i));
	}
}

int sum(int i) {
	int s = 0; //to store the sum
	while (i > 0) {
		s += fen[i];
		i += i - (i & (-i));
	}
	return s;
}


//Binary lifting in fenwick tree
int find(int k) {
	int curr = 0, ans = 0, prevsum = 0;
	for (int i = log2(n); i >= 0; i--) {
		if (ft[curr + (1 << i)] + prevsum < k) {
			curr = curr + (1 << i);
			prevsum += ft[curr];
		}
	}
	return (curr + 1);
}


int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	return 0;
}