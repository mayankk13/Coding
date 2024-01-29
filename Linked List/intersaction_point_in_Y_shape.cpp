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


//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2) {
    // Your Code Here
    int len1 = 0;
    int len2 = 0;
    
    Node* h1 = head1;
    Node* h2 = head2;
    
    while (h1->next != NULL) {
        len1++;
        h1 = h1->next;
    }
    while (h2->next != NULL) {
        len2++;
        h2 = h2->next;
    }
    
    int diff = abs(len1 - len2);
    
    if (len1 > len2) {
        while (diff != 0) {
            head1 = head1->next;
            diff--;
        }
    }
    if (len2 > len1) {
        while (diff != 0) {
            head2 = head2->next;
            diff--;
        }
    }
    
    while (head1 && head2) {
        if (head1 == head2) {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return -1;
}