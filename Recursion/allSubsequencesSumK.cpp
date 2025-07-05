/*
Given an array arr[] of length n and a number k, the task is to find all the subsequences 
of the array with sum of its elements equal to k.

input -
6
17 18 6 11 2 4
6

output -
6 
2 4 
*/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int idx, int sum, int target, vector<int>& curr, vector<vector<int>>& res, vector<int>& arr) {
        // base case
        if (idx == arr.size()) {
            // check if sum of current subset is equal to target
            if (sum == target) {
                res.push_back(curr);
            }
            return;
        }

        // add current element in the subset
        curr.push_back(arr[idx]);
        solve(idx+1, sum + arr[idx], target, curr, res, arr); 

        // skip the current element
        curr.pop_back();
        solve(idx+1, sum, target, curr, res, arr);
    }

    vector<vector<int>>  subsequencesSumK(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> curr;
        vector<vector<int>> res;

        solve(0, 0, target, curr, res, arr);

        return res;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int target;
    cin>> target;

    Solution ob;

    vector<vector<int>> res = ob.subsequencesSumK(arr, target);

    for (auto num: res) {
        for (auto i: num) {
            cout<<i <<" ";
        }
        cout<<endl;
    }

    return 0;
}