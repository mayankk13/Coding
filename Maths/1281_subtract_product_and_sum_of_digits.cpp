/*
Given an integer number n, return the difference between the product of its digits and the sum of its digits.

Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int temp = n;
        int sum = 0;
        int prod = 1;

        while (temp != 0) {
            int x = temp % 10;
            sum += x;
            prod = prod * x;

            temp = temp / 10;
        }

        return (prod - sum);
    }
};