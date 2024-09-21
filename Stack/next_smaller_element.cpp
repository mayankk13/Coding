/*
Nearest Smaller to right

input:
5
4 5 2 25 7 
output:
2 2 -1 7 -1 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        stack<int> st;

        for (int i = n-1; i >= 0; i--) {
            if (st.empty()) {
                res.push_back(-1);
            }
            else if (!st.empty() && st.top() < nums[i]) {
                res.push_back(st.top());
            }
            else if (!st.empty() && st.top() >= nums[i]) {
                while (!st.empty() && st.top() >= nums[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    res.push_back(-1);
                }
                else if (!st.empty() && st.top() < nums[i]) {
                    res.push_back(st.top());
                }
            }
            st.push(nums[i]);
        }
        reverse(res.begin(), res.end());

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
    vector<int> res = ob.nextSmallerElement(arr);

    for (int i = 0; i < n; i++) {
        cout<<res[i] <<" ";
    }
    cout<<endl;

    return 0;
}