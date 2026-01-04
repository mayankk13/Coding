#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> arr;
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;

        int minR = 0;
        int maxR = row - 1;
        int minC = 0;
        int maxC = col - 1;

        while ( count < (row * col)) {
            // traverse top row
            for (int i = minC; i <= maxC; i++) {
                arr.push_back(matrix[minR][i]);
                count++;
            }
            minR++;

            // traverse right col
            for (int i = minR; i <= maxR; i++) {
                arr.push_back(matrix[i][maxC]);
                count++;
            }
            maxC--;

            // traverse bottom row
            for (int i = maxC; i >= minC && count < (row * col); i--) {
                arr.push_back(matrix[maxR][i]);
                count++;
            }
            maxR--;

            // traverse left col
            for (int i = maxR; i >= minR && count < (row * col); i--) {
                arr.push_back(matrix[i][minC]);
                count++;
            }
            minC++;
        }

        return arr;
    }
};