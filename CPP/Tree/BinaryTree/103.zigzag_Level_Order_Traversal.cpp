/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, 
then right to left for the next level and alternate between).

        3
      /   \
     9     20
          /   \
        15     7 

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        queue<TreeNode*> q;
        if (root == NULL) {
            return res;
        }

        q.push(root); 
        int count = 1;
        while(!q.empty()) {
            
            int size = q.size();
            vector<int> v;

            while(size--) {
                TreeNode* t = q.front();
                q.pop();

                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }

                v.push_back(t->val);
            }
            if (count % 2 == 0) {
                reverse(v.begin(), v.end());
            }
            res.push_back(v);
            count++;
        }
        return res;
    }
};