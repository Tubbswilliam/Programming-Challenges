#include<bits/stdc++.h>
using namespace std;
//As usual we have to create the tree
struct Node {
	int data;
	Node*left;
	Node*right;
};
//Function to create a new node
Node* newNode(int key) {
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

//Functio to get the height of the tree
int height(Node*N) {
	if (N == NULL)return 0;
	return N->height;
}
//Function to get the maximum between nodes
int max(int a, int b) {
	return a < b ? b : a;
}

//Next step I will implement the rotations
//Right rotation
Node* rightRotate(Node *y) {
	Node*x = y->left;
	Node*T2 = x->right;
	//Lets rotate
	x->right = y;
	y->left = T2;

	//updating the new height
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	//return the new root after rotation
	return x;
}

//left rotation
Node* leftRotate(Node* x) {
	Node* y = x->right;
	Node*T2 = y->left;
	//rotate
	y->left = x;
	x->left = T2;

	//updating the new heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	//returning the new root
	return y;
}

//implement the balancng factor
int getBalance(Node* N) {
	if (N == NULL)return 0;
	return height(N->left) - height(N->right);
}

//Implement a helper function to insert a new node


int main() {

	return 0;
}