// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> posArr;
        vector<int> negArr;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                posArr.push_back(nums[i]);
            }
            else {
                negArr.push_back(nums[i]);
            }
        }

        for (int i = 0; i < posArr.size(); i++) {
            res.push_back(posArr[i]);
            res.push_back(negArr[i]);
        }

        return res;
    }
};