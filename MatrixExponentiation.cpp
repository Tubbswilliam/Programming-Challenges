//make use of the identity matrix
//Pseudocode of the matrix exponentiation
/*
mat power(mat A,int pow){
	mat res=identity matrix of n*n;
	for(int i=1;i<pow;i++){
		int res*=pow;
	}
	return res;
}
*/

#include<bits/stdc++.h>
using namespace std;
int N = 100;
int arr[N][N], identity[N][N];

void mul(int A[][N], int B[][N], int dim) {
	int res[dim + 1][dim + 1];
	for (int i = 1; i <= dim)
		for (int j = 1; j <= dim; j++) {
			res[i][j] = 0;
			for (int k = 1; k <= dim; k++) {
				res[i][j] += A[i][k] * B[k][j];
			}
		}
	for (int i = 1; i <= dim; i++)
		for (int j = 1; j <= dim; j++) {
			A[i][j] = res[i][j];
		}
}

void power(int A[][N], int dim, int n) {
	for (int i = 1; i <= dim; i++) {
		for (int j = 1; j <= dim; j++) {
			if (i == j)identity[i][j] = 1;
			else
				identity[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		mul(identity, A, dim);
	}
	for (int i = 1; i <= dim; i++) {
		for (int j = 1; j <= dim; j++) {
			A[i][j] = identity[i][j];
		}
	}
}
void printMat(int A[][N], int dim) {
	for (int i = 1; i <= dim; i++)
		for (int j = 1; j <= dim; j++) {
			cout << A[i][j] << " ";
			cout << "\n";
		}

}

int main() {
	int t, dim, n;
	cin >> t;
	while (t--) {
		cin >> dim >> n;
		for (int i = 1; i <= dim; i++) {
			for (int j = 1; j <= dim; j++)
				cin >> arr[i][j];
		}
	}
	power(arr, dim, n);
	printMat(arr, dim);
	return 0;
}