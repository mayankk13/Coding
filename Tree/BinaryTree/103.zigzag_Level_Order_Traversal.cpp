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