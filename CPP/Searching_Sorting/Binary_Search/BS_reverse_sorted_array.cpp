// Binary search

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
            else if (arr[mid] > target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
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