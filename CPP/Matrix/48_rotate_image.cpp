/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

Input:
1 2 3 
4 5 6
7 8 9  
Output:
7 4 1 
8 5 2
9 6 3
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = i+1; j < cols; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < rows; i++) {
            int low = 0;
            int high = cols - 1;

            while (low < high) {
                swap(matrix[i][low], matrix[i][high]);
                low++;
                high--;
            }
        }
    }
};

int main() {
    int m, n;
    cin>>m >>n;
    vector<vector<int>> arr(m, vector<int>(n));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>arr[i][j];
        }
    }
    
    Solution ob;
    ob.rotate(arr);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout<<arr[i][j] <<" ";
        }
        cout<<endl;
    }

    return 0;
}