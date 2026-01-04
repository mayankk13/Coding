/*
Algorithmic Steps:

    1. Create 2 Nodes dummy(to store actual summation result), Temp(which points to dummy)
    2. Take sum=0 ,carry=0 (to hold the sum results in 2 digit )
    3. In Loop,Check whether L1 || L2 till reaches NULL & carry till 0
    4. In If(LL!=NULL),Keep adding sum with L1->val & move to next node; applies same for L2
    5. Keep adding sum with carry.
    6. Get carry by sum/10
    7. Create new node by obtaining modulus of sum
    8. Assign temp->next =node; temp = temp->next;
    9. Return dummy->next;
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry;
            carry = sum / 10;

            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;

            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        return dummy->next;
    }   
};