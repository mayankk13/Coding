// merge two sorted arrays

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;

        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            }
            else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        // if nums2 is exaustd and nums1 is still left
        while (i < m) {
            res.push_back(nums1[i]);
            i++;
        }
        // if nums1 is exaustd and nums2 is still left
        while (j < n) {
            res.push_back(nums2[j]);
            j++;
        }
        // copy res to nums1
        for (int i = 0; i < res.size(); i++) {
            nums1[i] = res[i];
        }
    }
};