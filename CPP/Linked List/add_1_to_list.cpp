#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution
{
    public:
    Node* reverse(Node* head) {
        // reverse the list 
        Node* curr = head;
        Node* nxt;
        Node* pre = NULL;
        
        while (curr != NULL) {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        return pre;
    }
    
    Node* addOne(Node *head) {
        head = reverse(head);
        Node* curr = head;
        bool f = true;
        while (curr != NULL && f == true) {
            if (curr->data == 9 && curr->next == NULL) {
                curr->data = 1;
                Node* temp = new Node(0);
                temp->next = head;
                head = temp;
                curr = curr->next;
            }
            else if (curr->data == 9) {
                curr->data = 0;
                curr = curr->next;
            }
            else {
                curr->data += 1;
                curr = curr->next;
                f = false;
            }
        }
        head = reverse(head);
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends