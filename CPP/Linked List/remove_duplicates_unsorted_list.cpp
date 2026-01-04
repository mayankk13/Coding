#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) {
        // your code goes here
        Node* temp = head;
        Node*pre = NULL;
        unordered_map<int, int> mp;
        
        Node* curr = head;
        while (curr != NULL) {
            if (mp.find(curr->data) != mp.end()) {
                pre->next = curr->next;
            }
            else {
                mp[curr->data]++;
                pre = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};