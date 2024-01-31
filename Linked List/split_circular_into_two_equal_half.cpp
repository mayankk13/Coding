/*
Your Task:
Your task is to complete the given function splitList(), which takes 3 input parameters: 
The address of the head of the linked list, addresses of the head of the first and second halved 
resultant lists and Set the head1_ref and head2_ref to the first resultant list and second resultant list respectively.
*/

void splitList(Node *head, Node **head1_ref, Node **head2_ref) {
    // your code goes here
    Node *slow = head;
    Node *fast = head;
    
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1_ref = head;;
    *head2_ref = slow->next;
    slow->next = head;
    
    Node *curr = *head2_ref;
    while (curr->next != head) {
        curr = curr->next;
    }
    curr->next = *head2_ref;
    
}