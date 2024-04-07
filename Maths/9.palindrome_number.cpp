/*
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindromeM1(int x) {
        // Negatinve number cannot be palindrome
        if (x < 0) {
            return false;
        }
        // initialize rev to store reversed number
        int rev = 0;

        // create temp variable to store original value
        int temp = x;

        while (temp != 0) {
            // get the last digit of the number
            int digit = temp % 10;
            // append the extracted digit to the reversed number
            rev = rev * 10 + digit;
            // remove the last digit from the temp
            temp = temp / 10;
        }
        // Check if the reversed number is equal to the original number.
        return rev == x;
    }

    bool isPalindromeM2(int x) {
        string str = to_string(x);

        int start = 0;
        int end = str.length()-1;

        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    int x;
    cin>>x;

    Solution ob;

    cout<<ob.isPalindromeM1(x);

    return 0;
}