#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node*left;
	Node*right;
};

void bst() {
	int n, item;
	Node*p, *q, *root;
	cout << "Enter the number of nodes." << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		p = new Node;
		cin >> item;
		p->data = item;
		p->left = NULL;
		P->right = NULL;
	}
}

int main() {
	return 0;
}