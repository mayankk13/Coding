/*
Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element 
of the array in order of their appearance in the array. Next greater element of an element in the array is the 
nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. 
For example, next greater of the last element is always -1.

Example 1:
Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        // Initialize a vector to store the results
        vector<long long> res;
        // Initialize a stack to store indices of elements
        stack<long long> st;

        // Iterate over the array from right to left
        for (long long i = n-1; i >= 0; i--) {
            // While the stack is not empty and the top element of the stack is less than or equal to arr[i]
            if (st.size() > 0 && st.top() <= arr[i]) {
                // Pop elements from the stack until either it becomes empty or the top element is greater than arr[i]
                while (st.size() > 0 && st.top() <= arr[i]){
                    st.pop();
                }
                // If the stack becomes empty after popping elements, push -1 to the result vector
                if (st.size() == 0) {
                    res.push_back(-1);
                }
                // Otherwise, push the top element of the stack to the result vector
                else {
                    res.push_back(st.top());
                }
            }
            // if stack is empty push -1 in vector
            else if (st.size() == 0) {
                res.push_back(-1);
            }
            // If the top element of the stack is greater than arr[i], push it to the result vector
            else {
                res.push_back(st.top());
            }
            // Push the current element arr[i] to the stack
            st.push(arr[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends