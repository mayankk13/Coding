/*
Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.
input: 
4 5

1 2 1 4 8
3 7 8 5 1
8 7 7 3 1
8 1 2 7 9

output: 8 1 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // return common elements in each row
    vector<int> CommonElements(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        unordered_map<int, int> mp;
        vector<int> res;

        // initialize first elements with value 1
        for (int i = 0; i < cols; i++) {
             mp[mat[0][i]] = 1;
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // if element is present in map & is not duplicate in curr row
                if (mp[(mat[i][j])] == i) {
                    // increament element count in map by 1
                    mp[(mat[i][j])] += 1;
                }

                // if this is the last row
                if (i == rows - 1 && mp[(mat[i][j])] == rows) {
                    res.push_back(mat[i][j]);
                }
            }
        }

        return res;
    }

};

int main() {
    int rows, cols;
    cin>>rows >>cols;

    vector<vector<int>> mat(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin>>mat[i][j];
        }
    }
    Solution ob;

    vector<int> res = ob.CommonElements(mat);
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i] <<" "; 
    }
    cout<<endl;

    return 0;
}