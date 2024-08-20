/*
Binary Search

Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
    // Binary Search
    int binarySearch(int arr[], int n, int x, bool isLeftSearch) {
        int low = 0;
        int high = n - 1;
        int idx = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (x > arr[mid]) {
                low = mid + 1;
            }
            else if (x < arr[mid]) {
                high = mid - 1;
            }
            else {
                idx = mid;
                if (isLeftSearch) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }
        return idx;
    }
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int left = binarySearch(arr, n, x, true);
	    int right = binarySearch(arr, n, x, false);
	    
	    if (left == -1) {
	        return 0; 
	    }
	    else {
	        return (right - left + 1);
	    }
	    
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}