#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node (int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public: 
    Node* insert(Node* curr, int value) {
        Node* newNode = new Node(value);

        if (curr == NULL) {
            return newNode;
        }

        if (value < curr->data) {
            curr->left = insert(curr->left, value);
        }
        else if (value > curr->data) {
            curr->right = insert(curr->right, value);
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

    void preOrderTraversal(Node* curr) {
        if (curr != NULL) {
            cout<<curr->data <<" ";
            preOrderTraversal(curr->left);
            preOrderTraversal(curr->right);
        }
    }

    void postOrderTraversal(Node* curr) {
        if (curr != NULL) {
            postOrderTraversal(curr->left);
            postOrderTraversal(curr->right);
            cout<<curr->data <<" ";
        }
    }
};

int main() {
    Solution ob;
    int n;
    cin>>n;
    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        head = ob.insert(head, x);
    }

    ob.inOrderTraversal(head);
    cout<<endl;
    ob.preOrderTraversal(head);
    cout<<endl;
    ob.postOrderTraversal(head);

    return 0;
}