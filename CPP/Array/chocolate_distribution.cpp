/*
Given an array A[] of positive integers of size N,
There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given 
to a student is minimum.

N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        //code
        long long i = 0;
        long long j = m - 1;
        long long minn = INT_MAX;
        sort(a.begin(), a.end());
        
        while (j < n) {
            long long diff = a[j] - a[i];
            minn = min(minn, diff);
            i++;
            j++;
        }
        return minn;
    }   
};