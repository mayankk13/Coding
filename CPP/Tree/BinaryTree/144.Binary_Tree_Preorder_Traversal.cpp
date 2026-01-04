/*
Binary tree preorder traversal

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Input: root = [1,null,2,3]
Output: [1,2,3]
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void solve(TreeNode* root, vector<int> &res) {
        if (root != NULL) {
            res.push_back(root->val);
            solve(root->left, res);
            solve(root->right, res);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root, res);

        return res;
    }
};