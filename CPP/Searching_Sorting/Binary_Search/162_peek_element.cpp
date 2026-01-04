/*
A peak element is an element that is strictly greater than its neighbors.

input:
5
1 3 20 9 10
output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low  = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid > 0 && mid < n - 1) {
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
            else if (mid == 0) {
                if (nums[mid] > nums[1]) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
            else {
                if (nums[n-1] > nums[n-2]) {
                    return n-1;
                }
                else return n-2; 
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

    cout<<ob.findPeakElement(nums) <<endl;

    return 0;
}