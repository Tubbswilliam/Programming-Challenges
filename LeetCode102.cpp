/*
Given the root of a binary tree, return the level order traversal of its nodes' values.
(i.e., from left to right, level by level).

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*>Q;
        Q.push(root);
        while (!Q.empty()) {
            int size = Q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = Q.front();
                Q.pop();
                temp.push_back(curr->val);
                if (curr->left) Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
            }
            result.push_back(temp);
        }
        return result;
    }
};

int main() {return 0;}