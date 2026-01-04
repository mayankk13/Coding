/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, 
find if there is a celebrity in the party or not. A square NxN matrix M[][] is used to represent people at the party 
such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will 
always be 0. Return the index of the celebrity, if there is no celebrity return -1.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)

Example 1:
Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    // Method 1: Time = O(n^2), space = O(n)
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        vector<int> in(n, 0);   // number of incomming connections
        vector<int> out(n, 0);  // number of outgoing connections

        // traverse the friendship matrix to count inccmming and outgoing connections
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // if there is a friedship relation from person i to person j
                // incomming connection for person j and outgoing connection for persoon i
                if (M[i][j] == 1) {
                    in[j]++;
                    out[i]++;
                }
            }
        }
        // iterate over all the people to identify potential celebrity
        for (int i = 0; i < n; i++) {
            // if a person have n-1 incomming connction (all people know him) and
            // 0 outgoing connctions (he doesn't know anyone), he is CELEBRITY
            if (in[i] == n-1 && out[i] == 0) {
                // return ther index of celebrity
                return i;
            }
        }
        return -1;
    }

    // Method 2: Time = O(n), space = O(n)
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
