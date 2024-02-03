#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int, int>> res;
        Node* start = head;
        Node* end = head;
        
        while (end->next != NULL) {
            end = end->next;
        }
        
        // The condition while (start->data < end->data) in your code ensures that 
        // you are iterating through distinct pairs of nodes without duplicating the 
        // pairs or counting the same pair multiple times in reverse order.
        while (start->data < end->data) {
            if (start->data + end->data == target) {
                res.push_back({start->data, end->data});
                // res.push_back(make_pair(start, end))
                start = start->next;
                end = end->prev;
            }
            else if (start->data + end->data > target) {
                end = end->prev;
            }
            else {
                start = start->next;
            }
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}