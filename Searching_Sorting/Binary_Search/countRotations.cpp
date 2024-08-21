/*
Binary Search based C++ program to find number of rotations in a sorted and 
rotated array.

input: 
7
11 12 15 18 2 5 6 8 
output: 4
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRotations(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            if (nums[low] <= nums[high]) {
                return low;
            }
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
                return mid;
            }
            else if (nums[mid] <= nums[high]) {
                high = mid - 1;
            }
            else if (nums[mid] >= nums[low]){
                low = mid + 1;
            }
        }

        return -1;
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

    Solution ob;
    cout<<ob.countRotations(arr1) <<endl;

    return 0;
}