/*
Peak Index in a Mountain Array
You are given an integer mountain array arr of length n where the values increase to a peak element 
and then decrease. Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.
input:
6
1 3 4 9 2 1 
output: 3
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
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
};

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    Solution ob;

    cout<< ob.peakIndexInMountainArray(nums) <<endl;

    return 0;
}