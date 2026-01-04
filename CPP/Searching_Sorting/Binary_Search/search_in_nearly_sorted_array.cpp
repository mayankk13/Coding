/*
find in nearly sorted array.
Given a sorted array arr[] of size N, some elements of array are moved to either of 
the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1] i.e. arr[i] 
can only be swapped with either arr[i+1] or arr[i-1]. The task is to search for an element in this array.

input:
5
5 10 30 20 40
40
output: 4
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int binarySearch(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (mid >= low && nums[mid-1] == target) {
                return mid-1;
            }
            else if (mid <= high && nums[mid+1] == target) {
                return mid+1;
            }
            else if (nums[mid] < target) {
                low = mid + 2;
            }
            else {
                high = mid - 2;
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
    int target;
    cin>>target;

    cout<<ob.binarySearch(nums, target) <<endl;

    return 0;
}