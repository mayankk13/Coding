class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        int sum = 0;

        // find the maxleft of each element
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(height[i], leftMax[i-1]); 
        }

        // find the maxright of each element
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i+1]);
        }
        // The water stored will be the min( leftmax[i] , rightmax[i]) -height[i].For each
        // element at particular index
        for (int i = 0; i < n; i++) {
            sum += min(leftMax[i], rightMax[i]) - height[i];
        }
        return sum;
    }
};