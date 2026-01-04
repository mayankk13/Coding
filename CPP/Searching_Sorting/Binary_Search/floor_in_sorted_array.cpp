/*
Floor in a Sorted Array
Given a sorted array and a value x, the floor of x is the largest element in the array smaller 
than or equal to x. Write efficient functions to find the floor of x

You must write an algorithm with O(log n) runtime complexity.

input:
4
1 3 5 6
7
output: 6
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int floorSortedArray(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                res = nums[mid];
                low = mid + 1;
            }
            else if (nums[mid] > target){
                high = mid - 1;
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

    cout<<ob.floorSortedArray(nums, target) <<endl;

    return 0;
}