/*
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a 
tree where each node contains the sum of the left and right sub trees of the original tree. The values of 
leaf nodes are changed to 0.

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int treeSum(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int lSum = treeSum(root->left);
        int rSum = treeSum(root->right);
        
        int data = root->data;
        root->data = lSum + rSum;
        
        return data + lSum + rSum;
    }
    
    void toSumTree(Node *node) {
        // Your code here
        if (node == NULL) {
            return;
        }
        treeSum(node);
    }
};