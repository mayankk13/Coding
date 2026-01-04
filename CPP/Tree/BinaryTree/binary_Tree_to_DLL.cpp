/*
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in 
nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must 
be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be 
the head node of the DLL.

Note: H is the height of the tree and this space is used implicitly for the recursion stack.

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
    public: 
    void inorderTraversal(Node* root, Node*& prev, Node*& head) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left, prev, head);
        
        if (prev == NULL) {
            head = root;
        }
        else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        
        inorderTraversal(root->right, prev, head);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root) {
        // your code here
        if (root == NULL) {
            return NULL;
        }
        
        Node* head = NULL;
        Node* prev = NULL;
        
        inorderTraversal(root, prev, head);
        
        return head;
    }
};