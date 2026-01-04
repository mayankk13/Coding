#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsequenceSum(int idx, int currSum, int sum, vector<int>& arr, int n) {
        if (currSum > sum) {
            return 0;
        }

        if (idx == n) {
            if (currSum == sum) {
                return 1;
            }

            return 0;
        }

        return subsequenceSum(idx+1, currSum+arr[idx], sum, arr, n) 
            || subsequenceSum(idx+1, currSum, sum, arr, n);
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    Solution ob;

    cout<<ob.subsequenceSum(0, 0, sum, arr, n);

    return 0;
}