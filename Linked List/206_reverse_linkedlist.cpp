// Given the head of a singly linked list, reverse the list, and return the reversed list.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* pre = NULL;
        ListNode* nexxt;

        while (curr != NULL) {
            nexxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nexxt;
        }

        return pre;
    }
};