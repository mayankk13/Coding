/*
Given an array arr[] of N integers, calculate the median.
NOTE: Return the floor value of the median.
*/

#include<bits/stdc++.h>
using namespace std;

int find_median(vector<int> v) {
    // Code here.
    sort(v.begin(), v.end());
    int n = v.size();
    // when array have odd number of elements
    if (n % 2 != 0) {
        return v[floor(n/2)];
    }
    
    // when array have even number of elements
    int low = 0;
    int high = n-1;
    
    while (low < high) {
        low++;
        high--;
    }
    
    int med = floor((v[low] + v[high]) / 2);
    return med;
}