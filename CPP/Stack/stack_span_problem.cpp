/*
Stock span problem
This problem is similar to greater element to the right

input: 
7
100 80 60 70 60 75 85
output:
1 1 1 2 1 4 6 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> stockSpanProblem(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                res.push_back(-1);
            }
            else if (!st.empty() && st.top().first > nums[i]) {
                res.push_back(st.top().second);
            }
            else if (!st.empty() && st.top().first <= nums[i]) {
                while (!st.empty() && st.top().first <= nums[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    res.push_back(-1);
                }
                else if (!st.empty() && st.top().first > nums[i]) {
                    res.push_back(st.top().second);
                }
            }
            st.push({nums[i], i});
        }

        for (int i = 0; i < n; i++) {
            res[i] = i - res[i];
        }

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

    Solution ob;
    vector<int> res = ob.stockSpanProblem(arr);

    for (int i = 0; i < n; i++) {
        cout<<res[i] <<" ";
    }
    cout<<endl;

    return 0;
}