// Binary tree reverse order travrsal
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        stack<vector<int>> s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> v;

            for (int i = 0; i < size; i++) {
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
            s.push(v);
        }

        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};