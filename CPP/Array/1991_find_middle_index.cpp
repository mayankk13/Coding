/*
Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] 
+ ... + nums[nums.length-1].

Input: nums = [2,3,-1,8,4]
Output: 3
Explanation: The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int lSum = 0;
        int rSum = 0;

        for (int i = 0; i < n; i++) {
            rSum = sum - lSum - nums[i];
            if (lSum == rSum) {
                return i;
            }
            lSum += nums[i];
        }

        return -1;
    }
};