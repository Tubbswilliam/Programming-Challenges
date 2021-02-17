/*
//Binary Search Tree(BST)
//A binary tree in which for each node, value of all the nodes in the left subtree
//is lesser and value of all the nodes in the nodes in the right subtree is greater.

#include<bits/stdc++.h>
using namespace std;

struct BstNode {
	int data;
	BstNode*left;
	BstNode*right;
};
BstNode*GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode*root, int data) {
	if (root == NULL) {
		root = GetNewNode(data);
		return root;
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else
		root->right = Insert(root->right, data);
	return root;

}
//////////////////////////////////////////////////////////
bool search(BstNode*root, int data) {
	if (root == NULL)return false;
	else if (root->data == data)return true;
	else if (data <= root->data)return search(root->left, data);
	else return search(root->right, data);
}


int main() {
	BstNode*root = NULL;
	root = Insert(root, 78);
	root = Insert(root, 89);
	root = Insert(root, 29);
	root = Insert(root, 96);
	root = Insert(root, 90);
	root = Insert(root, 95);
	root = Insert(root, 80);
	int n;
	printf("Enter the number you want to search : ");
	cin >> n;
	if (search(root, n) == true)printf("Your number is in the BST ");
	else printf("Input the number %d in the BST", n);

	return 0;
}
*/

/*
//Given a BST find the minimum and maximum element in it
#include<bits/stdc++.h>
using namespace std;

struct BstNode {
	int data;
	BstNode*left;
	BstNode*right;
};
///////////////////////////////////////////////////////////////
BstNode*GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
////////////////////////////////////////////////////////////
BstNode* Insert(BstNode*root, int data) {
	if (root == NULL) {
		root = GetNewNode(data);
		return root;
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else
		root->right = Insert(root->right, data);
	return root;

}

////////////////////////////////////////////////////////
int FindMin(BstNode*root) {
	if (root == NULL) {
		printf("Tree is empty");
		return -1;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;

}

int FindMax(BstNode*root) {
	if (root == NULL) {
		printf("Tree is empty");
		return -1;
	}
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

int main() {
	BstNode*root = NULL;
	root = Insert(root, 78);
	root = Insert(root, 89);
	root = Insert(root, 29);
	root = Insert(root, 96);
	root = Insert(root, 90);
	root = Insert(root, 95);
	root = Insert(root, 80);
	printf("The minimum value is : %d \n", FindMin(root));
	printf("The maximum value is : %d \n", FindMax(root));

	return 0;
}

*/

//Finding the height of a binary tree
//Height of a tree can be defined as the number of edges in the longest peth from the node
//to a leaf node.
//Depth of a node can be defined as the number of edges from the root to that node

#include<bits/stdc++.h>
using namespace std;

struct BstNode {
	int data;
	BstNode*left;
	BstNode*right;
};
///////////////////////////////////////////////////////////////
BstNode*GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
////////////////////////////////////////////////////////////
BstNode* Insert(BstNode*root, int data) {
	if (root == NULL) {
		root = GetNewNode(data);
		return root;
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else
		root->right = Insert(root->right, data);
	return root;

}
/////////////////////////////////////////////////////////////////////
int FindHeight(BstNode*root) {
	if (root == NULL)return -1;
	return max(FindHeight(root->left), FindHeight(root->right)) + 1;

}
////////////////////////////////////////////////////////////////////////

int main() {
	BstNode*root = NULL;
	root = Insert(root, 78);
	root = Insert(root, 89);
	root = Insert(root, 29);
	root = Insert(root, 96);
	root = Insert(root, 90);
	root = Insert(root, 95);
	root = Insert(root, 80);
	root = Insert(root, 7);
	root = Insert(root, 85);
	root = Insert(root, 100);
	root = Insert(root, 1);
	root = Insert(root, 0);
	root = Insert(root, 20);
	root = Insert(root, 50);
	root = Insert(root, 140);
	root = Insert(root, 240);
	root = Insert(root, 230);
	root = Insert(root, 330);
	root = Insert(root, 300);
	root = Insert(root, 110);
	printf("The Height of the BST is : %d ", FindHeight(root));

	return 0;
}