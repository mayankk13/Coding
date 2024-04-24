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

    int heightOfTree(Node* curr) {
        if (curr == NULL) {
            return 0;
        }
        int maxLeft = heightOfTree(curr->left);
        int maxRight = heightOfTree(curr->right);

        int maxHeight = max(maxLeft, maxRight) + 1;

        return maxHeight;
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
    cout<<ob.heightOfTree(head) <<endl;

    return 0;
}