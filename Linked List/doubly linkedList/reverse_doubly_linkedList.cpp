#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node * next;
    Node * prev;
    Node (int x) {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

class Solution
{
    public:
    Node* reverseDLL(Node * head) {
        //Your code here
        Node* curr = head;
        Node* pre = NULL;
        Node* nxt = NULL;
        
        while (curr != NULL) {
            nxt = curr->next;
            curr->next = pre;
            curr->prev = nxt;
            pre = curr;
            curr = nxt;
        }
        return pre;
    }

    void displayList(Node *head) {
        //Head to Tail
        while(head->next) {
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<head->data;
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = new Node(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=new Node(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
	    Solution ob;
	    head=ob.reverseDLL(head);
	    
	    ob.displayList(head);
	    cout<<endl;
	}
	return 0;
}