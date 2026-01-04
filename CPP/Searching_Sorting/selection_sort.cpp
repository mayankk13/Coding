/*
Selection sort: 
    1. First we find the smallest element and swap it with the first element. This way we get the smallest element 
    at its correct position.
    2. Then we find the smallest among remaining elements (or second smallest) and swap it with the second element.

input: 64, 34, 25, 12, 22, 11, 90
output: 11 12 22 25 34 64 90
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size();
        // n-1 because we are doing j = i+1
        for (int i = 0; i < n-1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            
            if (i != minIndex) {
                swap(arr[i], arr[minIndex]);
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
    ob.selectionSort(arr, n);

    return 0;
}