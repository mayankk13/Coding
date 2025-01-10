/*
Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generatePermutations(vector<int> nums, int i, int j, vector<vector<int> >& res) {
        if (i == j - 1) {
            res.push_back(nums);
            return;
        }

        for (int k = i; k < j; k++) {
            if (i != k && nums[i] == nums[k]) {
                continue;
            }
            swap(nums[i], nums[k]);
            generatePermutations(nums, i+1, j, res);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        generatePermutations(nums, 0, nums.size(), res);

        return res;
    }
};