// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, 
// if you are at nums[i], you can jump to any nums[i + j] where:

// Example
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.



class Solution {
public:
    int jump(vector<int>& nums) {
        int step = nums[0];     // current position, which changes with each jump
        int maxR = nums[0];      // with each jump we will see can we get a better jump
        int jump = 1;            // number of jumps taken. 
        int n = nums.size();

        if (n == 1) {
            return 0;
        }
        else if (nums[0] == 0) {
            return -1;
        }
        else {
            for (int i = 1; i < n; i++) {
                // loop starts with 1 as first element is already covered.
                if (i == n-1) {
                    // index have reached last position
                    return jump;
                }
                maxR = max(maxR, i+nums[i]);
                // i + nums[i] calculates the furthest reachable index from the current position i.
                // This computes the sum of the curr index i and the max number of steps that can be taken from index i.
                step--;
                // As you move forward (i++), you decrement the step to simulate taking steps within the     
                // maximum reachable distance (maxR).
                if (step == 0) {
                    // the steps allowed within the current maximum reach (maxR) have been exhausted.
                    jump++;
                    if (i >= maxR) {
                        // If i is greater than or equal to maxR, it implies it's impossible to move further forward
                        return -1;
                    }
                    step = maxR - i; 
                    // It determines the remaining steps that can be taken from the current position 
                    // to extend the maximum reachable distance.
                }
            }
        }
        return jump;
    }
};