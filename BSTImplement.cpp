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

//Implementing the search algorithm.
//The search algorithm should return the deepest node in the tree.
Node*search(Node*root, int key) {
	if (root == NULL) {return NULL;}
	queue<Node*>q;
	Node*out = NULL;
	q.push(root);

	while (!q.empty()) {
		Node*temp = q.front();
		q.pop();
		if (temp->key == key) {
			out = temp;
			cout << "Present" << endl;
		}
		if (temp->left)q.push(temp->left);
		if (temp->right)q.push(temp->right);
	}
	return out;
}


int main() {
	root = createNode(3);
	root->left = createNode(2);
	root->right = createNode(6);
	root->left->left = createNode(7);
	root->left->right = createNode(9);
	root->right->left = createNode(10);
	root->right->right = createNode(12);
	Node* node = search(root, 9);
	return 0;
}