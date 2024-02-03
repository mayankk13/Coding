/*
Given a sorted linked list of distinct nodes (no two nodes have the same data) and an integer X. 
Count distinct triplets in the list that sum up to given integer X.

Input: LinkedList: 9->8->6->5->4->2->1,  X = 17
Output: 2
Explanation: Distinct triplets are (2, 6, 9) and (4, 5, 8) which have sum equal to X i.e 17.
*/

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

int countTriplets(struct Node* head, int x) { 
    // code here.
    vector<int> arr;
    Node* curr = head;
    
    while (curr != NULL) {
        arr.push_back(curr->data);
        curr = curr->next;
    }
    
    sort(arr.begin(), arr.end());
    int count = 0;
    
    for (int i = arr.size()-1; i >= 0; i--) {
        int j = 0;
        int k = i-1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == x) {
                count++;
                j++;
                k--;
            }
            else if (sum < x) {
                j++;
            }
            else {
                k--;
            }
        }
    }
    return count;
} 