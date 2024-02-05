#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void mergeSort(int arr[], int l, int r) {
        // only when size is two more
        if (r > l) {
            int m = l + (r - l) / 2;

            // sort the first and second half
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);

            // merge the sorted halves
            merge(arr, l, m, r);
        }
    }

    void merge(int arr[], int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        int left[n1];
        int right[n2];

        for (int i = 0; i < n1; i++) {
            left[i] = arr[low + i];
        }
        for (int i = 0; i < n2; i++) {
            right[i] = arr[mid + i + 1];
        }

        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            }
            else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = right[j];
            j++;
            k++;
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
    ob.mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout<<arr[i] <<" ";
    }
    cout<<endl;

    return 0;
}
