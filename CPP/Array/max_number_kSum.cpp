// In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
// Return the maximum number of operations you can perform on the array.
// Input: nums = [1,2,3,4], k = 5
// Output: 2

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size()-1;
        int count = 0;
        sort(nums.begin(), nums.end());

        while (low < high) {
            if (nums[low] + nums[high] == k) {
                count++;
                low++;
                high--;
            }
            else {
                if (nums[low] + nums[high] > k) {
                    high--;
                }
                else {
                    low++;
                }
            }
        }
        return count;
    }
};