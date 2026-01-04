/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach 
when you always travel preferring the left subtree over the right subtree. 

Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is 
the leaf node you could reach when you always travel preferring the right subtree over the left subtree. 
Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void leftTree(Node* root, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        
        if (root->left) {
            res.push_back(root->data);
            leftTree(root->left, res);
        }
        else if (root->right) {
            res.push_back(root->data);
            leftTree(root->right, res);
        }
    }

    void leaf(Node* root, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        leaf(root->left, res);
        if (!root->left && !root->right) {
            res.push_back(root->data);
        }
        leaf(root->right, res);
    }

    void rightTree(Node* root, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        
        if (root->right) {
            rightTree(root->right, res);
            res.push_back(root->data);
        }
        else if (root->left) {
            rightTree(root->left, res);
            res.push_back(root->data);
        }
    }
    vector <int> boundary(Node *root) {
        //Your code here
        vector<int> res;
        res.push_back(root->data);
        if (root->left == NULL && root->right ==NULL) { 
            return res;
        }
        leftTree(root->left, res);
        leaf(root, res);
        rightTree(root->right, res);

        return res;
    }
};