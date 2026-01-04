// Intersection of two arrays

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    // this func returns the position of the element x, if not present the nreturn -1.
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2)  {
        vector<int> res;
        unordered_map<int, int> mp;

        for (int i = 0; i < arr1.size(); i++) {
            mp[arr1[i]]++;
        }

        for (auto x: arr2) {
            if (mp[x] > 0) {
                res.push_back(x);
                mp[x] = 0;
            }
        }
        return res;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<int> arr1(m);
    vector<int> arr2(n);

    // Input elements for arr1
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    // Input elements for arr2
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    Solution ob;
    vector<int> res = ob.intersection(arr1, arr2);

    // Output the result
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}