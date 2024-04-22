/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring.

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                }
                else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};