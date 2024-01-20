class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;  // set because we do not care about duplicates

        int x, count = 1;
        int maxlen = 0;

        // Insert all elements of the array into the unordered set
        for (int i =0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        // Iterate through elements of set
        for (auto it : st) {
            // check if the current element is the start of the subsequence, 
            // i.e., previous element (curr - 1) does not exist
            if (st.find(it - 1) == st.end()) {
                count = 1;  // Reset the counter for a new sequence
                x = it + 1; // Start checking for consecutive elements from the next one

                // Continue checking for consecutive elements and updating the counter
                while (st.find(x) != st.end()) {
                    count++;
                    x++;
                }

                // Update the maximum length encountered so far
                maxlen = max(maxlen, count);
            } 
        }

        return maxlen;
    }
};