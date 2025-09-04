class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0], curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr = max(nums[i], nums[i] + curr);
            mx = max(curr, mx);
        }
        return mx;
    }
};