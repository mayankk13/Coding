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