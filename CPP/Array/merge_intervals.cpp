/*
This code merges overlapping intervals in a given list. 
The goal is to consolidate overlapping intervals into single intervals. 

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();   // numbers of intervals
        vector<vector<int>> result; // result vector to store merge intervals

        // step1: sort intervals based on their starting points
        sort(intervals.begin(), intervals.end());

        // step2: use a stack to track merge intervals
        stack<pair<int, int >> st;
        st.push({intervals[0][0], intervals[0][1]});

        // Step3: iterate through each intervals to merge overlaps
        for (int i = 1; i < n; i++) {
            // get teh interval at the top of the stack
            int start1 = st.top().first;
            int end1 = st.top().second;

            // get th current interval from the input
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            // check if the current interval overlaps with the interval of the stack
            if (end1 < start2) {
                // np overlap: push the current interval onto the stack
                st.push({start2, end2});
            } else {
                // ovrlap: Merge the intervals
                st.pop();   // remove the old intervals
                end1 = max(end1, end2);     // update the end point to the max end value    
                st.push({start1, end1});    // push the merge interval onto the stack
            } 
        }
        // Step4: Extract intervals from the stack into the result vector.
        while (!st.empty()) {
            result.push_back({st.top().first, st.top().second});
            st.pop();
        }

        // step5: sort the inteval (but this is unnecessary because of the earlier sort)
        // sort(result.begin(), result.end())
        return result;
    }
};