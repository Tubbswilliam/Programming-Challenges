#include<bits/stdc++.h>
using namespace std;
//As usual we have to create the tree
struct Node {
	int key;
	Node*left;
	Node*right;
	int height;
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
	x->right = T2;

	//updating the new heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	//returning the new root
	return y;
}

//implement the balancng factor
int getBalance(Node* N) {
	if (N == NULL)return 0;
	return (height(N->left)) - (height(N->right));
}

//Implement a helper function to insert a new node
Node* insert(Node*node, int key) {
	//normal BST insertion
	if (node == NULL)return (newNode(key));
	if (key < node->key)node->left = insert(node->left, key);
	else if (key > node->key)node->right = insert(node->right, key);
	else //That is if the key and nod->key are equal
		return node;

	//updating the height of the ancestor of the node
	node->height = 1 + max(height(node->left), height(node->right));

	//Balancing factor of this node ancestor
	int balance = getBalance(node);
	//If the node is unbalance then 4 cases have to be checked
	//left left case
	if (balance > 1 && key < node->left->key)return rightRotate(node);

	//right right
	if (balance < -1 && key > node->right->key)return leftRotate(node);

	//left right case
	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	//Right left case
	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	//Return the unchanged node pointer
	return node;
}

//Function to print the preorder traversal of the tree and
//the height of the tree

void preorder(Node*root) {
	if (root != NULL) {
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}

}

int main() {
	Node *root = NULL;
	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 6);
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 9);
	root = insert(root, 7);

	cout << "Preoder traversal of the Avl tree is : " << endl;
	preorder(root);
	return 0;
}