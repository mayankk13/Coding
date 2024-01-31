// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head== NULL || head->next == NULL) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow;
        ListNode *nexxt = NULL;
        ListNode *pre = NULL;

        while (curr != NULL) {
            nexxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nexxt;
        }

        while(pre && head) {
            if (head->val != pre->val) {
                return false;
            }
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};