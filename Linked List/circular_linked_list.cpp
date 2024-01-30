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

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head) {
   // Your code here
   if (head == NULL) {
       return false;
   }
   Node* curr = head;
   
   while (curr != NULL) {
       if (curr->next == head) {
           return true; 
       }
       curr = curr->next;
    }
    return false; 
}