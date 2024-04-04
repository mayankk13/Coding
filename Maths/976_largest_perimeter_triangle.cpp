/*
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed 
from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

Example 1:
Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());

        for (int i = nums.size()-1; i >= 2; i--) {
            if (nums[i] < nums[i-1] + nums[i-2]) {
                ans = max(ans, (nums[i] + nums[i-1] + nums[i-2]));
            }
        }
        
        return ans;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    Solution ob;
    cout<< ob.largestPerimeter(arr) <<endl;

    return 0;
}