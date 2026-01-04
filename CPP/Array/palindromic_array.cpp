/*
Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. 
Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int PalinArray(int a[], int n) {
    	// code here
    	for (int i = 0; i < n; i++) {
    	    string str = to_string(a[i]);
    	    int low = 0;
    	    int high = str.length()-1;
    	    while (low < high) {
    	        if (str[low] != str[high]) {
    	            return 0;
    	        }
    	        low++;
    	        high--;
    	    }
    	}
    	return 1;
    }
};