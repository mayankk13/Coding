/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateSubsets(vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& result) {
            // if we processed all subsets
            if (index == nums.size()) {
                // add current subset to the result
                result.push_back(currentSubset); 
                return;   
            }

            // include the current element
            currentSubset.push_back(nums[index]);
            generateSubsets(nums, index+1, currentSubset, result);

            // exclude current element - backtrack
            currentSubset.pop_back();
            generateSubsets(nums, index+1, currentSubset, result);

        }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;

        generateSubsets(nums, 0, currentSubset, result);

        return result;
    }
};