#include<bits/stdc++.h>
using namespace std;

struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;

    DLLNode (int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct compare {
    bool operator()(DLLNode* first, DLLNode* second) {
        return first->data > second->data;
    }
};

// function to sort a k sorted doubly linked list
class Solution {
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        if (head == NULL) {
            return head;
        }
        // create a min heap (priority queue) to maintain the order
        priority_queue<DLLNode*, vector<DLLNode*>, compare> minHeap;
        struct DLLNode* newHead = NULL;
        struct DLLNode* curr;
        
        // insert k+1 element in the min heap 
        for (int i = 0; head != NULL && i <= k; i++) {
            minHeap.push(head);
            head = head->next;
        }
        
        while (!minHeap.empty()) {
            if (newHead == NULL) {
                newHead = minHeap.top();
                newHead->prev = NULL;
                curr = minHeap.top();
            }
            else {
                curr->next = minHeap.top();
                minHeap.top()->prev = curr;
                curr = minHeap.top();
            }
            
            minHeap.pop();
            if (head != NULL) {
                minHeap.push(head);
                head = head->next;
            }
        }
        curr->next = NULL;
        return newHead;
    }
};