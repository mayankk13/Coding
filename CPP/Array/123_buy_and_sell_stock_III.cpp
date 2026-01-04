// Function to calculate the maximum profit by buying and selling stocks
int maxProfit(vector<int>& prices) {
    // Get the size of the prices vector
    int n = prices.size();
    
    // Arrays to store the maximum profit on the left and right side of each day
    int left[n];
    int right[n];

    // Variable to store the overall maximum profit
    int maxProfit = 0;

    // Variables to keep track of the minimum price on the left and maximum price on the right
    int leftmin = prices[0];
    int rightmax = prices[n-1];

    // Initialize the first elements of left and right arrays
    left[0] = 0;
    right[n-1] = 0;

    // If there are 0 or 1 elements in the prices vector, return 0 (no transactions can be made)
    if (n == 0 || n == 1) {
        return 0;
    }

    // Loop to calculate the maximum profit on the left side of each day
    for (int i = 1; i < n; i++) {
        // Update the minimum price on the left
        leftmin = min(leftmin, prices[i]);
        // Calculate the maximum profit on the left for the current day
        left[i] = max(left[i-1], prices[i] - leftmin);
    }

    // Loop to calculate the maximum profit on the right side of each day
    for (int j = n-2; j >= 0; j--) {
        // Update the maximum price on the right
        rightmax = max(rightmax, prices[j]);
        // Calculate the maximum profit on the right for the current day
        right[j] = max(right[j+1], rightmax - prices[j]);
    }

    // Loop to find the overall maximum profit by summing up left and right profits for each day
    for (int i = 0; i < n; i++) {
        maxProfit = max(maxProfit, left[i] + right[i]);
    }

    // Return the overall maximum profit
    return maxProfit;
}