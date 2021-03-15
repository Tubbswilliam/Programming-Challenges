#include<bits/stdc++.h>
using namespace std;
//The number of trees to form from an array is Cn!((n+1)!n!)
struct Node {
	int key;
	Node*left;
	Node*right;
};
Node *root = NULL;
Node*createNode(int key) {
	Node*node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}



int main() {
	root = createNode(3);
	root->left = createNode(2);
	root->right = createNode(6);
	root->left->left = createNode(7);
	root->left->right = createNode(9);
	root->right->left = createNode(10);
	root->right->right = createNode(12);

	cout << root->left->key;
	return 0;
}