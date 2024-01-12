#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bubbleSort(int arr[], int n) {
        for (int i = 0; i < n-1; i ++) {
            // int index = i;
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j+1] < arr[j]) {
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
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
	ob.bubbleSort(arr, n);
	
	for (int i = 0; i < n; i++) {
	    cout<<arr[i] <<" ";
	}
	cout<<endl;

	return 0;
}