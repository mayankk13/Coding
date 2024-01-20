class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = floor(n / 3);
        vector<int> res;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (auto i : mp) {
            if (i.second > k) {
                res.push_back(i.first);
            }
        }

        return res;
    }
};