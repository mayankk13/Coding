/*
Ceiling in a Sorted Array
Given a sorted array and a value x, the ceiling of x is the smallest element in an array greater than 
or equal to x, and the floor is the greatest element smaller than or equal to x. 
Assume that the array is sorted in non-decreasing order. Write efficient functions to find the 
floor and ceiling of x. 

You must write an algorithm with O(log n) runtime complexity.

input:
4
1 3 5 6

output: 6
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int ceilSortedArray(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                res = nums[mid];
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        } 

        return res;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }

    Solution ob;
    int target;
    cin>>target;

    cout<<ob.ceilSortedArray(nums, target) <<endl;

    return 0;
}