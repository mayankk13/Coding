/*
common elemetn in all row of the matrix
Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.

input:
4 5
1 2 1 4 8 
3 7 8 5 1 
8 7 7 3 1 
8 1 2 7 9 

output:
8 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:   
    vector<int> commonElments(vector<vector<int>> arr) {
        unordered_map<int, int> mp;
        int row = arr.size();
        int col = arr[0].size();
        vector<int> res;

        // initiate first row element with value 1
        for (int i = 0; i < col; i++) {
            mp[arr[0][i]] = 1;
        }

        // traverse the matrix
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {

                // if element is present in map and
                // is not duplicated in current row
                if (mp[arr[i][j]] == i) {

                    // increment count of curr element in map by 1
                    mp[arr[i][j]] = i + 1;

                    if (i == row - 1 && mp[arr[i][j]] == row) {
                        res.push_back(arr[i][j]);
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    int m, n;
    cin>> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>> arr[i][j];
        }
    }
    Solution ob;
    vector<int> res = ob.commonElments(arr);
    for (int i = 0; i < res.size(); i++) {
        cout<< res[i] <<" ";
    }
    cout<<endl;
    return 0;
}
