#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node*left;
	Node*right;
};

void bst(int arr[], int n) {
	int i;
	Node*p, *q, *root;
	//cout << "Enter the number of nodes." << endl;
	//cin >> n;
	for (i = 0; i < n; i++) {
		p = new Node;
		//cin >> item;
		p->data = arr[i];
		p->left = NULL;
		p->right = NULL;

		if (i == 0)root = p;
		else {
			q = root;
			while (1) {
				if (p->data > q->data)
				{
					if (q->right == NULL) {
						q->right = p;
						break;
					}
					else {
						q = q->right;
					}
				}
				else {
					if (q->left == NULL) {
						q->left = p;
						break;
					}
					else {
						q = q->left;
					}
				}
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bst(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}