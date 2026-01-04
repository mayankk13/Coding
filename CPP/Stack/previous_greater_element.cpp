// previous greater element
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> previousGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                res.push_back(-1);
            }
            else if (!st.empty() && st.top() > nums[i]) {
                res.push_back(st.top());
            }
            else if (!st.empty() && st.top() <= nums[i]) {
                while (st.size() > 0 && st.top() <= nums[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    res.push_back(-1);
                }
                else if (!st.empty() && st.top() > nums[i]) {
                    res.push_back(st.top());
                }
            }

            st.push(nums[i]);
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
    vector<int> res = ob.previousGreaterElement(arr);

    for (int i = 0; i < n; i++) {
        cout<<res[i] <<" ";
    }
    cout<<endl;

    return 0;
}