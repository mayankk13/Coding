// Find the max height/depth of a binary tree

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
    Node* insert(Node* curr, int val) {
        Node* newNode = new Node(val);
        if (curr == NULL) {
            return newNode;
        }
        if (val < curr->data) {
            curr->left = insert(curr->left, val);
        }
        else {
            curr->right = insert(curr->right, val);
        }

        return curr;
    }

    void inOrderTraversal(Node* curr) {
        if (curr != NULL) {
            inOrderTraversal(curr->left);
            cout<<curr->data <<" ";
            inOrderTraversal(curr->right);
        }
    }

    vector<vector<int>> levelOrderTraversal(Node* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
                v.push_back(node->data);
            }
            res.push_back(v);
        }
        return res;
    }
};

int main() {
    Solution ob;
    Node* head = NULL;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        head = ob.insert(head, x);
    }
    ob.inOrderTraversal(head);
    cout<<endl;
    vector<vector<int>> res = ob.levelOrderTraversal(head);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}