#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node (int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    Node* push(Node* head, int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return head;
        }

        newNode->next = head;
        head->prev = newNode;

        head = newNode;
        return head;
    }

    Node* insertAfter(Node* head, int key, int data) {
        Node* newNode = new Node(data);

        Node* curr = head;
        while (curr != NULL) {
            if (curr->data == key) {
                newNode->next = curr->next;
                newNode->prev = curr;
                curr->next = newNode;
            }
            curr = curr->next;
        }

        return head;
    }

    Node* insertBefore(Node* head, int key, int data) {
        Node* newNode = new Node(data);

        Node* curr = head;
        while (curr != NULL) {
            if (curr->data == key) {
                newNode->next = curr;
                newNode->prev = curr->prev;
                if (curr->prev != NULL) {
                    curr->prev->next = newNode;
                } else {
                    // If inserting before the head, update head
                    head = newNode;
                }
                curr->prev = newNode;
                break;
            }
            curr = curr->next;
        }
        return head;
    }

    Node* append(Node* head, int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return head;
        }

        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;

        return head;

    }

    void printList(Node* head) {
        Node* curr = head;
        while (curr != NULL) {
            cout<<curr->data <<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
};

int main() {
    int n;
    cin>>n;
    Solution ob;
    Node* head = NULL;

    // 23 4 11
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        head = ob.append(head, x);
    }
    ob.printList(head);

    head = ob.push(head, 7);
    ob.printList(head);

    head = ob.insertAfter(head, 4, 13);
    ob.printList(head);

    // head = ob.insertBefore(head, 11, 5);
    // ob.printList(head);

    return 0;
}