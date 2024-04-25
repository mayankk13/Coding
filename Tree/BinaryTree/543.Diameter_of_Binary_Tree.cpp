// Find the diameter of a binary tree

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

    int heightOfTree(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = heightOfTree(root->left);
        int rightHeight = heightOfTree(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    int diaMeterOfBinaryTree(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int lHeight = heightOfTree(root->left);
        int rHeight = heightOfTree(root->right);

        int lDiameter = diaMeterOfBinaryTree(root->left);
        int rDiameter = diaMeterOfBinaryTree(root->right);

        return max((lHeight + rHeight), max(lDiameter, rDiameter));
    }
};

int main() {
    Solution ob;
    // Node* root = NULL;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    ob.inOrderTraversal(root);
    cout<<endl;
    cout<<"diameter of the Tree: " <<ob.diaMeterOfBinaryTree(root);
    return 0;
}