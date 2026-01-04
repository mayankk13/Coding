/*
Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Input: root = [1,null,2,3]
Output: [1,3,2]
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode (int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root, res);
        return res;
    }

    void solve(TreeNode* root, vector<int> &res) {
        if (root != NULL) {
            solve(root->left, res);
            res.push_back(root->val);
            solve(root->right, res);
        }
    }
};