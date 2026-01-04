#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n) {
    vector<int> pos, neg;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            neg.push_back(arr[i]);
        }
        else {
            pos.push_back(arr[i]);
        }
    }    

    int i = 0; 
    int j = 0;
    int k = 0;

    while (i < pos.size() && j < neg.size()) {
        if (k % 2 == 0) {
            arr[k] = pos[i];
            i++;
        }
        else {
            arr[k] = neg[j];
            j++;
        }
        k++;
    }

    while (i < pos.size()) {
        arr[k] = pos[i];
        i++;
        k++;
    }
    while (j < neg.size()) {
        arr[k] = neg[j];
        j++;
        k++;
    }
}