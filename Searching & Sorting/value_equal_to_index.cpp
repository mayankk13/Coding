/*
Given an array Arr of N positive integers. Your task is to find the elements whose value is equal 
to that of its index value ( Consider 1-based indexing ).

Note: There can be more than one element in the array which have the same value as its index. 
You need to include every such element's index. Follows 1-based indexing of the array.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

	vector<int> valueEqualToIndex(int arr[], int n) {
	    // code here
	    vector<int> res;
	    for (int i = 0; i < n; i++) {
	        if (i+1 == arr[i]) {
	            res.push_back(arr[i]);
	        }
	    }
	    
	    return res;
	}
};