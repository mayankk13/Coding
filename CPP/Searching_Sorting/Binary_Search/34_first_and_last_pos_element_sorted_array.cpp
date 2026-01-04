/*
Binary Search

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position 
of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target,  bool isSearchingLeft) {
        int low  = 0;
        int high = nums.size()-1;
        int idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                idx = mid;
                if (isSearchingLeft) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else if (target > nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);

        return {left, right};
    }
};

int main() {
    int m;
    cin >> m;
    
    vector<int> arr1(m);

    // Input elements for arr1
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    int x;
    cin>> x;
    Solution ob;
    vector<int> res = ob.searchRange(arr1, x);

    for (int i = 0; i < res.size(); i++) {
        cout<<res[i] <<" ";
    }
    cout<<endl;

    return 0;
}