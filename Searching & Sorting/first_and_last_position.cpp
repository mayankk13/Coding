/*
Given a sorted array arr containing n elements with possibly some duplicate, the task is to find the first 
and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  
2 5
Explanation: 
First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> find(int arr[], int n , int x ) {
        // code here
        int first = -1;
        int last = -1;
        vector<int> res;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                last = i;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            if (arr[i] == x) {
                first = i;
            }
        }
        
        res.push_back(first);
        res.push_back(last);
        
        return res;
    }
};