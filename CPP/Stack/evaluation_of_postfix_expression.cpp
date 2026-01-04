/*
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. 
Operators will only include the basic arithmetic operators like *, /, + and -.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S) {
        // Your code here
        stack<int> st;
        
        for (int i = 0; i < S.length(); i++) {
            if (S[i] >= '0' && S[i] <= '9') {
                st.push(S[i]-'0');
            }
            else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                if (S[i] == '+') {
                    st.push(a + b);
                }
                else if (S[i] == '-') {
                    st.push(b - a);
                }
                else if (S[i] == '*') {
                    st.push(a * b);
                }      
                else if (S[i] == '/') {
                    st.push( b / a);
                }
            }
        }
        return st.top();
    }
};