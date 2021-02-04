//Lowest Common Ancestor using inOrder Transversal
#include<bits\stdc++.h>
using namespace std;

node *LCA(nodes *root, node *p, node *q) {
	if (root == NULL)return NULL;
	if (root == p || root = q)return root;
	left = LCA(root->left, p, q);
	right = LCA(root->right, p, q);

	if (left != NULL && right != NULL)
		return root;
	else
		return (left ? left : right)
	}