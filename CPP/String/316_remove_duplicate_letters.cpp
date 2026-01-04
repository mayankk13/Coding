#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        // vector to store last occurance index of each character
        vector<int> last_occurance(26, -1);
        // vector to track wheather char been already used in the result
        vector<bool> used(26, false);
        stack<char> st;     // to build the result string

        // calculate the last occurance of each char in the string
        for (int i = 0; i < s.length(); i++) {
            last_occurance[s[i] - 'a'] = i;
        }

        // Iterate through the string
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            
            // If the character is not already used in the result
            if (!used[curr - 'a']) {
                // Pop elements from the stack if they are greater and have a later occurrence
                while (!st.empty() && curr < st.top() && last_occurance[st.top() - 'a'] > i) {
                    used[st.top() - 'a'] = false;   // Mark the character as unused
                    st.pop();   // Pop the character from the stack
                }
                // Push the current character onto the stack
                st.push(curr);
                used[curr - 'a'] = true;    // Mark the character as used
            }
        }
        // Construct the result string in reverse order from the stack
        string res(st.size(), ' ');

        for (int i = st.size()-1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};