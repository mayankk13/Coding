/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is 
the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6       7

Top view will be: 4 2 1 3 7
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
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        //Your code here
        vector<int> res;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        
        if(root == NULL) {
            return res;
        }
        q.push({root, 0});
        
        while (!q.empty()) {
            Node* t = q.front().first;
            int h = q.front().second;
            q.pop();
            
            if (!mp[h]) {
                mp[h] = t->data;
            }
            
            if (t->left) {
                q.push({t->left, h-1});
            }
            if (t->right) {
                q.push({t->right, h+1});
            }
        }
        for (auto x : mp) {
            res.push_back(x.second);
        }
        return res;
    }
};

