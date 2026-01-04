#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key) {
    // Your code goes here
    if (*head == NULL) {
        return;
    }
    Node* prev = *head;
    Node* curr = prev->next;
    
    while (curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    if ((*head)->data == key) {
        *head = (*head)->next;
    }
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref) {
    // Your code goes here
     
    Node* curr = *head_ref;
    Node* pre = NULL;
    Node* nxt = NULL;
    
    while (curr != NULL) {
        nxt = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nxt;
    }
    *head_ref = pre->next;
}