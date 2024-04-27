/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
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
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> res;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        
        if (root == NULL) {
            return res;
        }
        q.push({root, 0});
        while(!q.empty()) {
            Node* t = q.front().first;
            int h = q.front().second;
            
            q.pop();
            mp[h] = t->data;
            
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