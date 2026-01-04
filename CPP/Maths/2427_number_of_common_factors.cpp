// Find number of common factors between two numbers

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 1;
        int n = a < b? a : b;
        for (int i = 2; i <= n; i++) {
            if (a % i == 0 && b % i == 0) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int a, b;
    cin>>a >>b;

    Solution ob;

    cout<<ob.commonFactors(a, b);

    return 0;
}

