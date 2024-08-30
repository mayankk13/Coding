/*
Minimum Difference Element in a Sorted Array
input:
5
1 3 8 10 15
14
output: 4
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int minDifferenceElement(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

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
        int left = abs(nums[low] - target);
        int right = abs(nums[high] - target);

        return left < right ? low : high;
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

    cout<<ob.minDifferenceElement(nums, target) <<endl;

    return 0;
}