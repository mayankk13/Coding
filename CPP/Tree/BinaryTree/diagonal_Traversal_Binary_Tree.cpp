/*
Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree 
belonging to same line. If the diagonal element are present in two different subtress then left subtree diagonal 
element should be taken first and then right subtree.

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4

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
    vector<int> diagonalTraversal(Node* root) {
        vector<int> res;
        queue<Node*> q;
        
        if (root == NULL) {
            return res;
        }

        q.push(root);
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            while(temp) {
                if (temp->left) {
                    q.push(temp->left);
                }
                res.push_back(temp->data);
                temp = temp->right;
            }
        }
        return res;
    }
};