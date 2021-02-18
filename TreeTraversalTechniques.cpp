//In this section I will do the three tree traversal techniques that is:
//BFS,DFS,PreOrder,Inorder and PostOrder
//Time Complexity for the algorithm is O(n) while space is O(h)
/*
#include<bits\stdc++.h>
using namespace std;
STRUCT nODE{
	char data;
	Node*left;
	Node*right;
};
//////////////////LevelOrder or BFS///////////////////////////////
void LevelOrder(Node*root) {
	if (root == NULL)return;
	queue<Node*>Q;
	Q.push(root);
	while (Q!empty()) {
		Node*current = Q.front();
		prtintf("current->data %d ", current->data);
		if (current->left != NULL)Q.push(current->left);
		if (current->right != NULL)Q.push(current->left);
		Q.pop();


	}
}
////////////////////////PreOrder///////////////////////////////
void PreOrder(Node*root) {
	if (root == NULL)return;
	printf("%c", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
/////////////////////////InOrder////////////////////////////////
void InOrder(Node*root) {
	if (root == NULL)return;
	InOrder(root->left);
	printf("%c", root->data);
	InOrder(root->right);
}

/////////////////////////////POstOrder //////////////////////////
void PostOrder(Node*root) {
	if (root == NULL)return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c", root->data);
}


////////////////////////////////////////////////////////////////
int main() {return 0;}


*/

//Checking if the Tree is a Binary search Tree
#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node*left;
	Node*right;
};

bool IsSubtreeLesser(Node*root, int value) {
	if (root == NULL)return;
	if ((root->data <= value)
	        && IsSubtreeLesser(root->left, value)
	        && IsSubtreeLesser(root->right, value))
		return true;
	else
		return false;

}
bool IsSubtreeGreater(Node*root, int value) {
	if (root == NULL)return;
	if ((root->data <= value)
	        && IsSubtreeGreater(root->left, value)
	        && IsSubtreeGreater(root->right, value))
		return true;
	else
		return false;
}
///////////////////Below is the check function/////////////////////////////////
//For this algo time complexity is O(n^2)
bool IsBST(Node*root) {
	if (IsSubtreeLesser(root->left, root->data)
	        && IsSubtreeGreater(root->right, root->data)
	        && IsBST(root->left)
	        && IsBST(root->right))
		return true;
	else
		return false;

}

///////////////////Recursion class on the check function are expensive
///////////////Hence need for a better faster approach.
bool IsBST_Better_util(Node*root, int minValue, int maxValue) {
	if (root == NULL)return;
	if ((root->data < maxValue) && (root->data > minValue)
	        && IsBST_Better_util(root->left, minValue, root->data)
	        && IsBST_Better_util(root->right, root->data, maxValue))
		return true;
	else
		return false;
}
bool IsBinarySearchTree(Node*root) {
	return IsBST_Better_util(root, INT_MIN, INT_MAX)
}
//For the above algo time complexity is O(n)
//////////////////////////////////////////////////////////////////////
//Deleting a node from BST
// Case 1:No child
// Case 2:One child
// Case 3: Two children

// steps for case 3:
// find min in right subtree
// copy the value in the targetted node
// Delete duplicate from right subtree
//////////or ////////////////////////////////////////////
// steps for case 3:
// find max in left subtree
// copy the value in the targetted node
// Delete duplicate from left subtree

Node*Delete(Node*root, int data) {
	//1st we need to find it
	if (root == NULL)return root;
	else if (data < root->data)root->left = Delete(root->left, data);
	else if (data > root->data)root->right = Delete(root->right, data);
	else {
		//Case 1: No child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child
		else if (root->left == NULL) {
			Node*temp = root;
			root = root->right;
			delete temp;

		}
		else if (root->right == NULL) {
			Node*temp = root;
			root = root->left;
			delete temp;
		}
		else {
			Node*temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}

	}
	return root;

}
////////////////////////////////////////////////////////////////

int main() {return 0;}


* /


//In order succesor in a binary tree/////////////////////////
//we introduce one more pointer that is the parent pointer

struct Node {
	int data;
	Node*left;
	Node*right;
	Node*parent;

};
//Function to find the minimum value in a BST
Node*FindMin(Node*root) {
	if (root == NULL)return NULL;
	while (root->left != NULL)root = root->left;
	return root;
}

// Function to find successor
Node*Getsuccessor(Node*root, int data) {
	//Search for the node O(h)
	Node*current = Find(root, data);
	if (current == NULL)return NULL;
	//Case 1:Node has a right subtree
	if (current->right != NULL) {
		return FindMin(current->right);
	}
	//Case 2: No right subtree O(h)
	else {
		Node*successor = NULL;
		Node*ancestor = root;
		while (ancestor != current) {
			if (current->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return ancestor;

	}
}