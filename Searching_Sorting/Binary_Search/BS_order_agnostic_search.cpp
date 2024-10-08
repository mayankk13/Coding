// Binary search
// Given a sorted array of numbers, find if a given number ‘key’ is present in the array. 
// Though we know that the array is sorted, we don’t know if it’s sorted in ascending or descending order. . 

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int binarySearch(vector<int>& arr, int target)  {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                return mid;
            }
            if (arr[low] > arr[high]) {
                if (arr[mid] > target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            else {
                if (arr[mid] > target) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }    
        }
    }
};

int main() {
    int m;
    cin >> m;
    
    vector<int> arr1(m);

    // Input elements for arr1
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    int x;
    cin>> x;
    Solution ob;
    cout<<ob.binarySearch(arr1, x) <<endl;

    return 0;
}