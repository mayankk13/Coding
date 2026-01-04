class Solution {
public:
    void mergeSorting(ListNode** head) {
        ListNode* curr = *head; // make current pointer
        ListNode* first;    // for the first half
        ListNode* second;   // for the second half
        
        // if linked list is null or just having a single elemrnt then simple 
        // return. because we don't have to do anything
        if (!curr || !curr->next) {
            return; 
        }
        findMiddle(curr, &first, &second);

        mergeSorting(&first);
        mergeSorting(&second);

        *head = mergeBoth(first, second);
    }

    ListNode* mergeBoth(ListNode* first, ListNode* second) {
        ListNode* ans = NULL;
        if (first == NULL) {
            return second;
        }
        else if (second == NULL) {
            return first;
        }

        if (first->val <= second->val) {
            ans = first;
            ans->next = mergeBoth(first->next, second);
        }
        else {
            ans = second;
            ans->next = mergeBoth(first, second->next);
        }
        return ans;
    }

    void findMiddle(ListNode* curr, ListNode** first, ListNode** second) {
        ListNode* slow = curr; // make a slow pointer
        ListNode* fast = curr -> next; // make a fast pointer
        
        // then we move our fast upto it not become null, means not reach on last position
        while(fast != NULL)
        {
            fast = fast -> next;
            if(fast != NULL)
            {
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        
        // after this assign curr to first
        *first = curr;
        *second = slow -> next; // second to slow next
        slow -> next = NULL; // and put slow next to null
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        mergeSorting(&head);

        return head;
    }
};