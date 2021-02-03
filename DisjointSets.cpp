#include<bits\stdc++.h>
//Disjoint set is a prerequisite of Kruskal's Algorithm.
//Disjoint set operations include(find(),Union()
//The parent of a set points to itself
/*Function to find a number in a D.set Pseudo code
find(n){
	while(1){
		if(n==parent[n])return n;
		else
			n=parent[n];
	}
}



or recursivelyyyyyyyy

firn(n){
	if(n==parent[n])return n;
	else
		return find(parent[n])
}

*/

/*Union operation pseudo code
union(a,b){
	a=find(a);
	b=find(b);
	if(a==b)return;
	else
		parent[a]=b;
}
*/
/*
//It appears that when we try to use the above algorithms somehow we might get a TLE
//There for we get away by using a path compression or union by rank technique.
//In order to reduce the complexity of Find operation, we use path compression technique.
Iterative find function using path compression
find(a){
	vector<int>v;
	while(parent[a]>0){
		v.push_back(a);
		a=parent[a];
	}
	for(int i=0;i<v.size();i++){
		parent[v[i]]=a;
	}
	return a;
}


//Recursive function using path compression
find(a){
	if(parent[a]<0)return a;
	else{
		int x=1;
		parent[a]=x;
		return x;
	}
}


The above find function with path compression can be written as follows
find(a){
	if(parent[a]<0)return a;
	return parent[a]=find(parent[a]);
}

*/

//Union by rank will optimize the code running time in the merger or union operation
//In this technique the set with higher number of elements becomes the parent.
//This technique is also known as merge smaller into bigger.
int par[10001], R[10001];
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	if (R[a] > R[b]) {
		par[b] = a;
		R[a] += R[b];
	} else {
		par[a] = b;
		R[b] += R[a];
	}

}

using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		par[i] = -1, R[i] = 1;
	}

	return 0;
}