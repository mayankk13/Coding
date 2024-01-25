/*
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid = 0;

        while (mid <= end) {
            if (nums[mid] == 0) {
                int temp = nums[start];
                nums[start] = nums[mid];
                nums[mid] = temp;
                start++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }

            else if (nums[mid] == 2) {
                int temp2 = nums[end];
                nums[end] = nums[mid];
                nums[mid] = temp2;
                end--;
            }
        }
    }
};