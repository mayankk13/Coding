class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mulLeft = 1;
        int mulRight = 1;
        int maxProd = INT_MIN;

        for (int i = 0; i < n; i++) {
            mulLeft *= nums[i];
            mulRight *= nums[n - i - 1];
            
            maxProd = max({maxProd, mulLeft, mulRight});
            if (mulLeft == 0) {
                mulLeft = 1;
            } 
            if (mulRight == 0) {
                mulRight = 1;
            } 
        }

        return maxProd;
    }
};