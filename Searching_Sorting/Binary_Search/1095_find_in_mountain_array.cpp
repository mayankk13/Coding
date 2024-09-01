/*
Find an element in Bitonic array.
Given a bitonic sequence of n distinct elements, and an integer x, the task is to write a 
program to find given element x in the bitonic sequence in O(log n) time. 

input: 
9
1 3 9 6 5 4 2 1 0
4
output: 5
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int binarySearchAsc(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (target > nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }

    int binarySearchDsc(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            else if (target > nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }

    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            }
            else if (nums[mid+1] > nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }

    int findInMountainArray(vector<int>& nums, int target) {
        int n = nums.size();
        int peek = peakIndexInMountainArray(nums);
        int left  = binarySearchAsc(nums, 0, peek, target);
        if (left != -1) {
            return left;
        }
        else {
            return binarySearchDsc(nums, peek+1, n-1, target);
        }

        return -1;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    int target;
    cin>>target;
    Solution ob;

    cout<< ob.findInMountainArray(nums, target) <<endl;

    return 0;
}