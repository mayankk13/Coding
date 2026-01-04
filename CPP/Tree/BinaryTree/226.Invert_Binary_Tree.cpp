// Invert a binary tree

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

    Node* invertBinaryTree(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        if (root->left != NULL) {
            invertBinaryTree(root->left);
        }
        if (root->right != NULL) {
            invertBinaryTree(root->right);
        }

        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};

int main() {
    Solution ob;
    Node* root = NULL;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        root = ob.insert(root, x);
    }

    ob.inOrderTraversal(root);
    cout<<endl;
    root = ob.invertBinaryTree(root);
    ob.inOrderTraversal(root);

    return 0;
}