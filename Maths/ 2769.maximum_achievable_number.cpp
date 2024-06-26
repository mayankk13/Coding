/*
You are given two integers, num and t.

An integer x is called achievable if it can become equal to num after applying the following operation no more than t times:

Increase or decrease x by 1, and simultaneously increase or decrease num by 1.
Return the maximum possible achievable number. It can be proven that there exists at least one achievable number.

Example 1:

Input: num = 4, t = 1
Output: 6
Explanation: The maximum achievable number is x = 6; it can become equal to num after performing this operation:
1- Decrease x by 1, and increase num by 1. Now, x = 5 and num = 5. 
It can be proven that there is no achievable number larger than 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + (t * 2);
    }
};

int main() {
    int n, t;
    cin>>n >>t;

    Solution ob;

    cout<<ob.theMaximumAchievableX(n, t);

    return 0;
}
