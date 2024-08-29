/*
Find position of an element in a sorted array of infinite numbers
input:
25
1 4 7 10 13 16 19 22 25 28 31 34 37 40 43 46 49 52 55 58 61 64 67 70 73
22
output: 7
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
            else if (target > nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }

    int findPosition(vector<int>& nums, int target) {
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