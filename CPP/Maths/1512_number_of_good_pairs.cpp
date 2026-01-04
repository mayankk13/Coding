/*
Given an array of integers nums, return the number of good pairs. A pair (i, j) is called good if nums[i] == nums[j] 
and i < j.

input: [1,2,3,1,1,3]
output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        int count = 0;

        for (int num : nums) {
            if (map.find(num) != map.end()) {
                count += map[num];
            }
            map[num]++;
        }

        return count;
    }
};