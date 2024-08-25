/*
find in nearly sorted array.
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

input:
4
1 3 5 6
7
output: 4
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
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

    cout<<ob.searchInsert(nums, target) <<endl;

    return 0;
}