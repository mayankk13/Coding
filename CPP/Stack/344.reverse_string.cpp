/*
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
        }

        vector<char> str;
        while (!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }

        for (int i = 0; i < s.size(); i++) {
            s[i] = str[i];
        }
    }
};