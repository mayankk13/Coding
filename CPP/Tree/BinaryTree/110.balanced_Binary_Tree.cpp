/*
Height-Balanced
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never 
differs by more than one.

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5
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
    int heightOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int lHeight = heightOfBinaryTree(root->left);
        int rHeight = heightOfBinaryTree(root->right);

        return max(lHeight, rHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        int lHeight = heightOfBinaryTree(root->left);
        int rHeight = heightOfBinaryTree(root->right);

        if (abs(lHeight - rHeight) > 1) {
            return false;
        }

        bool lBalance = isBalanced(root->left);
        bool rBalance = isBalanced(root->right);

        return (lBalance && rBalance);
    }
};