#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            // i started with second element as we assume first element is already sorted.
            int key = arr[i];   // for every element we will store in a variable and find its correct position in left sorted array.
            int j = i - 1;
            // we will start from the first left to the key element and will go till the first element and
            // till key is greater element left to it.
            while (j >= 0 &&  arr[j] > key) {
                arr[j + 1] = arr[j];    // moving elements to its right until we reach to element smaller than key
                j--;
            }
            arr[j + 1] = key;   // since element at j is smaller than key. we set j + 1 as key.
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
    ob.insertionSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout<<arr[i] <<" ";
    }
    cout<<endl;

    return 0;
}