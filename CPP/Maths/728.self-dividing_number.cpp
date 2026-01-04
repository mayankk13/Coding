/*
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
A self-dividing number is not allowed to contain the digit zero.

Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right].

Example 1:

Input: left = 1, right = 22
Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                res.push_back(i);
            }
        }
        return res;
    }

    bool isSelfDividing(int num) {
        int temp = num;
        while (num != 0) {
            int digit = num % 10;
            // if digit is zero or if it doesn't divide the number evenly, returns false.
            if (digit == 0 || temp % digit != 0) {
                return false;
            }
            num = num / 10;
        }

        return true;
    }
};

int main() {
    int left, right;

    cin>>left >>right;

    Solution ob;
    vector<int> res = ob.selfDividingNumbers(left, right);

    for (int i = 0; i < res.size(); i++) {
        cout<<res[i] <<" ";
    }
    cout<<endl;

    return 0;
}