/*
Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree 
and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

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
    int idx = 0;    // index to track the current position in the preorder traversal
    unordered_map<int, int> mp;     // map to store the indeces of element int the inorder traversal 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx = 0;    // reset the index to 0 for each tree contruction
        mp.clear();     // clear the map before building the new tree
        int n = preorder.size();    // the size of the tree

        // build the tree to store the indeces of element in the inorder traversal 
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;     
        }

        // call the solve func recursively to construct the tree
        TreeNode* root = solve(preorder, inorder, 0, n-1);

        return root;    // Return the root of the constructed tree.
    }

    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int lb, int ub) {
        // if lb > ub that means there is no node in this subtree
        if (lb > ub) {
            return NULL;    // Return NULL indicating an empty subtree.
        }

        // create the new node using the curr value from preorder traversal
        TreeNode* res = new TreeNode(preorder[idx++]);
        
        // if lb == ub, it means it the leaf node
        if (lb == ub) {
            return res;     // Return the leaf node.
        }

        // find the index of the curr node's value in inorder traversal
        int mid = mp[res->val];

        // Recursively construct the left subtree using elements to the left of the current node in the inorder traversal.
        res->left = solve(preorder, inorder, lb, mid-1);
        // Recursively construct the right subtree using elements to the right of the current node in the inorder traversal.
        res->right = solve(preorder, inorder, mid+1, ub);

        return res;     // Return the constructed subtree rooted at 'res'.
    }
};