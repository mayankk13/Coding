/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generatePermutations(vector<int>& nums, int index, vector<vector<int>>& result) {
        // Base case: If index is at the last position, we have a valid permutation
        if (index == nums.size()) {
            result.push_back(nums);
            return; 
        }

        // Recursive case: Swap the current element with every other element and recurse
        for (int i = index; i < nums.size(); i++) {
            // Swap to place the i-th element at the current index
            swap(nums[index], nums[i]);

            // Recur for the next index
            generatePermutations(nums, index + 1, result);

            // backtrack: undo the swap to restore the original order
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generatePermutations(nums, 0, result);

        return result;
    }
};