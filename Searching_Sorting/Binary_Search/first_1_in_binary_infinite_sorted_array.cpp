/*
Find position of first 1 in a sorted array of infinite numbers of 0s and 1s
input:
25
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1
1
output: 15
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return res;
    }

    int findPosition(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = 1;
        int val = nums[0];

        while (val < target) {
            low = high;
            high = high * 2;
            val = nums[high];
        }

        int res = binarySearch(nums, low, high, target);

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

    cout<<ob.findPosition(nums, target) <<endl;

    return 0;
}