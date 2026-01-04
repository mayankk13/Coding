#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k) {
        // Your code here
        // This line performs a right-shift operstion on the integer n by k positions and
        // stores the result in variable bit.
        
        // Right-shifting n by k positions means that you are moving each bit in the binary 
        // representation of n k positions to the right. This is essentially a division by 2^k. 
        // For example, if n is 12 (binary: 1100) and k is 1, then bit will be 6 (binary: 0110).
        int bit = n >> k;
        
        // This line of code performs a bitwise AND operation between the variable bit and the constant 1.
        
        // This is because the AND operation with 1 will result in bit itself if its LSB is 1, and it will 
        // result in 0 if its LSB is 0.
        return bit & 1;
    }
};

int main() {
    int t;
    cin >> t; // taking testcases
    while (t--) {
        long long n;
        cin >> n; // input n
        int k;
        cin >> k; // bit number k
        Solution obj;
        if (obj.checkKthBit(n, k))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}