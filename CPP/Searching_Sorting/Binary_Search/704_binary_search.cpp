// Binary search

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    // this func returns the position of the element x, if not present the nreturn -1.
    int binarySearch(vector<int> &arr, int low, int high, int x) {
       while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                return mid;
            }
            else if (arr[mid] > x) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
       }
        return -1;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int ele;
        cin>>ele;
        arr[i] = ele;
    }
    int x;
    cin>>x;

    Solution ob;
    cout<<ob.binarySearch(arr, 0, n-1, x);

    return 0;
}