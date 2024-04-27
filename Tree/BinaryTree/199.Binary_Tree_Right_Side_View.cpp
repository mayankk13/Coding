/*
Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode (int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root == NULL) {
            return res;
        }

        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            res.push_back(q.back()->val);

            while(size--) {
                TreeNode* t = q.front();
                q.pop();

                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }
        }
        return res;
    }
};