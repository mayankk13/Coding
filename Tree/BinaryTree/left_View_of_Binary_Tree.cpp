#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
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

    vector<int> leftView(Node* root) {
        vector<int> res;
        queue<Node*> q;

        if (root == NULL) {
            return res;
        }
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            res.push_back(q.front()->data);
            
            while (size--) {
                Node* t = q.front();
                q.pop();

                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }
        }
        return res;
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
    vector<int> res = ob.leftView(root);
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i] <<" ";
    }
    cout<<endl;

    return 0;
}

