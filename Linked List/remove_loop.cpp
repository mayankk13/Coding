class Solution
{
    public:
    //Function to remove a loop in the linked list.
    Node* detectLoop (Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                // The meeting point is the starting point of the loop
                return fast;
            }
        }
        return NULL;
    }
    
    void removeLoop(Node* head) {
        // code here
        // just remove the loop without losing any nodes
       
        Node* isLoop = detectLoop(head);
        // If there is a loop, remove it
        if (isLoop != NULL) {
            Node* curr = isLoop;
            while (curr->next != isLoop) {
                curr = curr->next;
            }
            curr->next = NULL;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<Node *, int>myMap;
        
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        myMap[head]=num;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail]=num;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends