// Given an array arr[] denoting heights of N towers and a positive integer K.
// For each tower, you must perform exactly one of the following operations exactly once.

// Increase the height of the tower by K
// Decrease the height of the tower by K
// Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int ans = arr[n-1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;
        
        for (int i = 0; i < n-1; i++) {
            int minn = min(smallest, arr[i+1] - k);
            int maxx = max(largest, arr[i] + k);
            if (minn < 0) {
                continue;
            }
            
            ans = min(ans, maxx - minn);
        }
        
        return ans;
    }
};