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

int main() {

	return 0;
}