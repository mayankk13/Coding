/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

Example 1:
Input: s = "()[]{}"
Output: true

Example 2:
Input: s = "(]"
Output: false
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                if (s[i] == ']' && st.top() == '[') {
                    st.pop();
                }
                else if (s[i] == '}' && st.top() == '{') {
                    st.pop();
                }
                else if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};

int main() {
    string str;
    cin>>str;

    Solution ob;

    cout<<ob.isValid(str);

    return 0;
}