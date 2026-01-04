/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            if (nums[0] >= target) {
                return 1;
            }
            return 0;
        }
        int i = 0;      // start of the window
        int j = 0;      // end of the window
        int sum = 0;    // current sum of the elements in the window    
        int sum1 = 0;   // sum of all elements of array
        int res = INT_MAX;   // initialize the res with max possible value.

        // calculate the sum of all elements in the array
        for (int i = 0; i < n; i++) {
            sum1 += nums[i];
        }

        // sliding window approach to find smallest sunarray with value greater than target
        while (i < n && j < n) {
            sum += nums[j];

            if (sum >= target) {
                // if sum is greater than target update the ans
                res = min(res, j - i + 1);
                // move the window to the right by increamenting the index value i
                i = i + 1;
                j = i;

                sum = 0;    // Reset the sum for the new window
            }
            else {
                j++;    // move the window to the right
            }
        }

        // if sum of all element is less than target 
        if (sum1 < target) {
            return 0;
        }

        return res;
    }
};