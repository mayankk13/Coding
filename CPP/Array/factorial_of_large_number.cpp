#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> factorialOfLargeNmber(int N) {
        int carry = 0;
        int multi = 0;
        vector<int> arr;
        arr.push_back(1);   //By convention, the factorial of 0 is considered to be 1. 
        // Then, as you iterate through the numbers from 1 to N, you multiply the current 
        // array with the current value of i to get the updated array representing the factorial.

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < arr.size(); j++) {
                // Multiply each element of the array with the current value of i
                multi = i * arr[j] + carry;
                arr[j] = multi % 10;    // Store the unit digit in the array
                carry = multi / 10;     // Update carry for the next iteration
            }

            // Handle thr remaining carry by adding new digit to the arry
            while (carry) {
                arr.push_back(carry % 10);
                carry = carry / 10;
            }
        }

        reverse(arr.begin(), arr.end());

        return arr;
    }

    void printNumber(vector<int>& res) {
        for (int i = 0; i < res.size(); i++) {
            cout<<res[i] <<" ";
        }
        cout<<endl;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> result;

    Solution ob;
    result = ob.factorialOfLargeNmber(n);
    ob.printNumber(result);

    return 0;
}