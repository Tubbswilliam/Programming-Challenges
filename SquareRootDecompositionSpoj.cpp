//SQRT Decomposition is an algorithm used
//to answer range query problems where Fenwick Tree and segment trees fail


//SQRT Dcompstn implementation

/*
int getMin(int l,int r){
	int LB=l/BLK;
	int RB=r/BLK;
	int mn= INT_MAX;

	if(LB==RB){
		for(int i=l;i<r;i++){
			mn=min(mn,arr[i])
		}
	else{
		for(int i=l;i<BLK*(LB+1);i++)
			mn=min(mn,ar[i]);
		for(int i=LB+1;i<RB;i++)
			mn=min(mn,F[i]);
		for(int i=BLK*RB;i<=r;i++)
			mn=min(mn,ar[i]);
	}

	return min;
}

*/



/*
Problem

Given an array of integers and queries of the form L,R,
how many elements exist in the given range?
*/

/*
//Basic template of the Mo's Algorithm

for (int i = 0; i < q; i++) {
	int L = Q[i].l; //l
	int R = Q[i].r; //r
	int idx = Q[i].i; //i

	//extending the range
	while (MR < R)MR++, add(MR);
	while (ML > L)ML--, add(ML);

	//reducing the range
	while (MR > R)remove(MR), MR--;
	while (ML < L)remove(ML), ML++;

	ans[idx] = count;
}

*/

/*
//Solution to the spoj Problem
#include<bits/stdc++.h>
using namespace std;
#define BLOCK 555

struct query {
	int l;
	int r;
	int i;
};

query Q[200001];
int ar[30001];
int ans[200001];
int freq[1000001];
int cnt = 0; //counting the number of unique elements

bool comp(query a, query b) {
	if (a.l / BLOCK != b.l / BLOCK)
		return a.l / BLOCK < b.l / BLOCK;
	return a.r < b.r;

}

void add(int pos) {
	freq[ar[pos]]++;
	if (freq[ar[pos]] == 1)
		cnt++;

}

void remove(int pos) {
	freq[ar[pos]]--;
	if (freq[ar[pos]] == 0)
		cnt--;
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

	int n, q;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> ar[i];
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> Q[i].l >> Q[i].r;
		Q[i].i = i, Q[i].l--, Q[i].r--;//Reducing L and R cos of 1 indexing from the question
	}

	sort(Q, Q + q, comp);

//Now Mo's algorithm
	int ML = 0, MR = -1;
	for (int i = 0; i < q; i++) {
		int L = Q[i].l; //l
		int R = Q[i].r; //r
		int idx = Q[i].i; //i

		//extending the range
		while (MR < R)MR++, add(MR);
		while (ML > L)ML--, add(ML);

		//reducing the range
		while (MR > R)remove(MR), MR--;
		while (ML < L)remove(ML), ML++;

		ans[idx] = cnt;
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";


	return 0;
}

*/

//CodeForces problem
/*

An array of positive integers a1, a2, ..., an is given.
Let us consider its arbitrary subarray al, al + 1..., ar,
where 1 ≤ l ≤ r ≤ n. For every positive integer s denote by
Ks the number of occurrences of s into the subarray.
We call the power of the subarray the sum of products Ks·Ks·s for every
positive integer s.The sum contains only finite number of nonzero summands as
the number of different values in the array is indeed finite.

You should calculate the power of t given subarrays.


*/

//Solution to the codeForces Powerful Array Problem
#include<bits/stdc++.h>
using namespace std;
#define BLOCK 555

struct query {
	int l;
	int r;
	int i;
};

query Q[200001];
int ar[30001];
int ans[200001];
int freq[1000001];
int power = 0; //counting the number of unique elements

bool comp(query a, query b) {
	if (a.l / BLOCK != b.l / BLOCK)
		return a.l / BLOCK < b.l / BLOCK;
	return a.r < b.r;

}

void add(int pos) {
	int cnt = freq[ar[pos]];
	freq[ar[pos]]++;

	power -= (cnt * cnt) * ar[pos];
	cnt++;
	power += (cnt * cnt) * ar[pos];

}

void remove(int pos) {
	int cnt = freq[ar[pos]];
	freq[ar[pos]]--;

	power -= (cnt * cnt) * ar[pos];
	cnt--;
	power += (cnt * cnt) * ar[pos];
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

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++)
		cin >> ar[i];
	for (int i = 0; i < q; i++) {
		cin >> Q[i].l >> Q[i].r;
		Q[i].i = i, Q[i].l--, Q[i].r--;//Reducing L and R cos of 1 indexing from the question
	}

	sort(Q, Q + q, comp);

//Now Mo's algorithm
	int ML = 0, MR = -1;
	for (int i = 0; i < q; i++) {
		int L = Q[i].l; //l
		int R = Q[i].r; //r
		int idx = Q[i].i; //i

		//extending the range
		while (MR < R)MR++, add(MR);
		while (ML > L)ML--, add(ML);

		//reducing the range
		while (MR > R)remove(MR), MR--;
		while (ML < L)remove(ML), ML++;

		ans[idx] = power;
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";


	return 0;
}
