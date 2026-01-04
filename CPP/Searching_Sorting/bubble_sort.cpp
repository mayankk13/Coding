/*
Bubble Sort

We sort the array using multiple passes. After the first pass, the maximum element goes to end (its correct position). 
Same way, after second pass, the second largest element goes to second last position and so on.

input: 64, 34, 25, 12, 22, 11, 90
output: 11 12 22 25 34 64 90
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        // since we are checking for j + 1, we need to end before n - 1
        for (int i = 0; i < n-1; i++) {
            bool swaped;
            // for any i element after n - i - 1 will always be sorted
            // hence ending before n - i - 1
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j+1]);
                    swaped = true;
                }
            }
            // If no two elements were swapped, then break
            if (!swaped) {
                break;
            }
        }
    }
};


int main() {
	int n;
	cin>>n;
	int arr[n];

	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	
	Solution ob;
	ob.bubbleSort(arr, n);
	
	for (int i = 0; i < n; i++) {
	    cout<<arr[i] <<" ";
	}
	cout<<endl;

	return 0;
}