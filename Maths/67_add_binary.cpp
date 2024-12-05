#include<bits/stdc++.h>
using namespace std;

// Class containing the solution for the Add Binary problem
class Solution {
public:
    string addBinary(string a, string b) {
        string result = ""; // To store the final binary result
        int carry = 0;      // To keep track of the carry during binary addition
        int i = a.size() - 1; // Pointer to traverse string 'a' from right to left
        int j = b.size() - 1; // Pointer to traverse string 'b' from right to left

        // Loop until both strings are exhausted and there's no carry left
        while (i >= 0 || j >= 0 || carry > 0) {
            // Get the current bit from 'a' or 0 if we've exhausted 'a'
            int bitA = (i >= 0) ? a[i] - '0' : 0;

            // Get the current bit from 'b' or 0 if we've exhausted 'b'
            int bitB = (j >= 0) ? b[j] - '0' : 0;

            // Calculate the sum of the two bits and the carry
            int sum = bitA + bitB + carry;

            // Update the carry for the next iteration (binary carry is sum / 2)
            carry = sum / 2;

            // Add the current bit to the result (binary bit is sum % 2)
            result += (sum % 2) + '0';

            // Move the pointers to the left for both strings
            i--;
            j--;
        }

        // Since we constructed the result in reverse order, reverse it back
        reverse(result.begin(), result.end());

        return result; // Return the final binary string
    }
};

int main() {
    Solution sol; // Create an instance of the solution class

    // Input binary strings
    string a, b;
    cout << "Enter first binary string: ";
    cin >> a;
    cout << "Enter second binary string: ";
    cin >> b;

    // Compute the sum of the binary strings
    string sum = sol.addBinary(a, b);

    // Output the result
    cout << "Sum of binary strings: " << sum << endl;

    return 0; // Exit the program
}