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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;

        ListNode* head1 = headA;
        ListNode* head2 = headB;

        while (head1->next != NULL) {
            len1++;
            head1 = head1->next;
        }
        while (head2->next != NULL) {
            len2++;
            head2 = head2->next;
        }
        int diff = abs(len1 - len2);
        if (len1 > len2) {
            while (diff != 0) {
                headA = headA->next;
                diff--;
            }
        }
        if (len2 > len1) {
            while (diff != 0) {
                headB = headB->next;
                diff--;
            }
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};