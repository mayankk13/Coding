/*
Largest Rectangle in Histogram
input:
6
2 1 5 6 2 3
output: 10
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> left;
        vector<int> right;
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                left.push_back(-1);
            }
            else if (!st.empty() && st.top().first < nums[i]) {
                left.push_back(st.top().second);
            }
            else if (!st.empty() && st.top().first >= nums[i]) {
                while (!st.empty() && st.top().first >= nums[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    left.push_back(-1);
                }
                else if (!st.empty() && st.top().first < nums[i]) {
                    left.push_back(st.top().second);
                }
            }
            st.push({nums[i], i});
        }
        while (!st.empty()) {
            st.pop();
        }

        for (int i = n-1; i >= 0; i--) {
            if (st.empty()) {
                right.push_back(-1);
            }
            else if (!st.empty() && st.top().first < nums[i]) {
                right.push_back(st.top().second);
            }
            else if (!st.empty() && st.top().first >= nums[i]) {
                while (!st.empty() && st.top().first >= nums[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    right.push_back(-1);
                }
                else if (!st.empty() && st.top().first < nums[i]) {
                    right.push_back(st.top().second);
                }
            }
            st.push({nums[i], i});
        }

        for (int i = 0; i < n; i++) {
            nums[i] = (right[i] - left[i] - 1) * nums[i];
        }

        int maxx = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxx) {
                maxx = nums[i];
            }
        }

        return maxx;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    Solution ob;
    cout<<"Area is: " <<ob.largestRectangleArea(arr);

    return 0;
}