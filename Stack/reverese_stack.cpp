/* 
You are given a stack St. You have to reverse the stack using recursion.
Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void insertAtBottom(stack<int> &St, int val) {
        if (St.empty()) {
            St.push(val);
            return;
        }
        
        int ele = St.top();
        St.pop();
        
        insertAtBottom(St, val);
        St.push(ele);
    }
    
    // Using Recursion : O(N^2) O(N^2) Not exactly
    void ReverseM1(stack<int> &St){
        if (St.empty()) {
            return;
        }
        
        int ele = St.top();
        St.pop();
        
        ReverseM1(St);
        insertAtBottom(St, ele);
    }

    // Using Queue : O(2N) O(N) //Auxiliary
    void ReverseM2(stack<int> &St) {
        queue<int> q;
        
        while (!St.empty()) {
            q.push(St.top());
            St.pop();
        }
        
        while (!q.empty()) {
            St.push(q.front());
            q.pop();
        }
    }
};

int main() {
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    Solution ob;
    ob.ReverseM1(st);
    ob.ReverseM2(st);
}