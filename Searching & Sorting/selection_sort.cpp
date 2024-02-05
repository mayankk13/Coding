#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int selectionSort(int arr[], int n) {
        int index;
        for (int i = 0; i < n-1; i++) {
            index = i;
            for (int j = i+1; j < n; j++) {
                if (arr[j] < arr[index]) {
                    index = j;
                }
            }
            if (index != i) {
                int temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
            }
        }
        for (int i = 0; i < n; i++) {
            cout<<arr[i] <<" ";
        }
        cout<<endl;

        return 0;
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