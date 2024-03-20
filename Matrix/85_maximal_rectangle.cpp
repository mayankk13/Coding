#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaHistogram(vector<int> &heights) {
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int left = i;
            int right = i;

            while (left > 0 && heights[left-1] >= heights[i]) {
                left--;
            }
            while (right < heights.size() - 1 && heights[right+1] >= heights[i]) {
                right++;
            }
            int area = (right - left + 1) * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int row = matrix.size();
        int cols = matrix[0].size();
        vector<int>currRow(cols, 0);
        int maxAns = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    currRow[j] += 1;
                }
                else {
                    currRow[j] = 0;
                }
            }
            maxAns = max(maxAns, maxAreaHistogram(currRow));
        }

        return maxAns;
    }
};