#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode (int data) {
        val = data;
        next = NULL;
    }
};

class Solution {
public:
    ListNode *reverse(ListNode* head, int k, int length) {
        // base case
        if (head == NULL || k > length) {
            return head;
        }
        // Initialize pointers
        ListNode *curr = head;
        ListNode *nexxt;
        ListNode *pre = NULL;
        int count = 0;

        // reverse k nodes
        while (curr != NULL && count < k && k <= length) {
            nexxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nexxt;
            count++;
        }
        // Update length
        length = length - k;
        // If there are more nodes left, recursively reverse the next group
        if (nexxt != NULL) {
            // update the next pointer of the current reversed group's head to point to 
            // the next reversed group.
            head->next = reverse(nexxt, k, length);
        }
        // Return the new head of the reversed group
        return pre;
    }

    int length(ListNode *head) {
        ListNode *curr = head;
        int count = 0;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int len = length(head);
        return reverse(head, k, len);
    }
};