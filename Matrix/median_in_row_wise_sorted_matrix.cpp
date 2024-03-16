#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:

    int median(vector<vector<int>> &matrix, int R, int C){
        // code here
        // initialize lower and higher bounds for binary search
        int low = INT_MAX;
        int high = INT_MIN;
        
        // find the min value in the first column and max value in the last column
        for (int i = 0; i < R; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C-1]);
        }
        
        // calculate the index of median element in the flattenend 1D representation of 2D array
        int median_ind = (R * C) / 2;
        
        // Binary search for the median element
        while (low <= high) {
            // calculate the middle value
            int mid = low + (high - low) / 2;
            
            // cnt is the total count of elements that are less than or equal to the 
            // current middle value 'mid'
            int cnt = 0;
            for (int i = 0; i < R; i++) {
                // find the upper bound of the current row for the middle value
                // 'ub' represents count of elements in the current row less or equal to mid
                int ub = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                
                cnt += ub;
            }
            
            if (cnt > median_ind) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
