/*
There is an integer array nums sorted in ascending order (with distinct values).

input:
8
11 12 15 18 2 5 6 8
15
output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (target < nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }

    int rotatedBinarySearch(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
                idx = mid;
                break;
            }
            else if (nums[mid] <= nums[high]) {
                high = mid - 1;
            }
            else if (nums[mid] >= nums[low]) {
                low = mid + 1;
            }
        }
        
        int leftSearch = binarySearch(nums, 0, idx-1, target);
        int rightSearch = binarySearch(nums, idx, n-1, target);
        
        return leftSearch != -1 ? leftSearch : rightSearch;
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

    cout<<ob.rotatedBinarySearch(nums, target) <<endl;

    return 0;
}