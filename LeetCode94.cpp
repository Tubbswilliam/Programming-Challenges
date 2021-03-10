/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*>s;
		TreeNode* curr = root;
		vector<int>result;
		while (curr != NULL || !s.empty()) {
			while (curr != NULL) {
				s.push(curr);
				curr = curr->left;
			}
			curr = s.top();
			s.pop();
			result.push_back(curr->val);
			curr = curr->right;
		}
		return result;
	}
};
int main() {return 0;}