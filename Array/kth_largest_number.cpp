class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        return nums[nums.size()-k];
    }
};

// second appoach
// initialize a max heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;

        // iterate through the array and insert elements into the max heap
        for (auto i : nums) {
            heap.push(nums[i]);
        }

        // remove the k-1 largest elements
        for (int i = 0; i < k-1; i++) {
            heap.pop();
        }
        
        // return the kth element
        return heap.top();
    }
};