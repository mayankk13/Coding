// We want to find a larger number, but not too large - just the next larger one =>
// We want to avoid chaning the number in the left - it will increase the number too much =>
// Example: 4325413 -> we can only change the last two numbers and have 432531
// What if it was 432531 in the first place? 31 cannot be increased.
// Lets try 531 - still no
// 2531 - this can be incrased - the smallest number that can be used to incrase the 2 is 3. so for now we have 3521.
// Next we want to minimize 3521 - thats easier - just sort the numbers to the right of 3 - 3125. So the unswer is 4323125

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int k = -1;
        
        // Find the first element from the right that is smaller than its next element
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                k = i;
                break;
            }
        }
        if (k != -1) {
            int l = n-1;
            // Find the smallest element to the right of k that is larger than nums[k]
            while (nums[l] <= nums[k]) {
                l--;
            }
            // Swap nums[k] and nums[l]
            swap(nums[k], nums[l]);
        }
        
        // Reverse the elements to the right of k
        reverse(nums.begin()+k+1, nums.end());
    }
};