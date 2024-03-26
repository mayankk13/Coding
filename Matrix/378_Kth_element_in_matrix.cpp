/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth 
smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
You must find a solution with a memory complexity better than O(n2).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // first solution - O(n^2)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size(); 
        priority_queue <int, vector<int>, greater<int> > heap;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                heap.push(matrix[i][j]);
            }
        }

        for (int i = 0; i < k-1; i++) {
            heap.pop();
        }

        return heap.top();
    }

    
};