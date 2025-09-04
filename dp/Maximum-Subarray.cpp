class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane's algo
        int mx = nums[0], curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr = max(nums[i], nums[i] + curr);
            mx = max(curr, mx);
        }
        return mx;

        // also using dp
        // vector<int> dp(nums.size(),0);
        // int mx=nums[0];
        // dp[0]=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     dp[i]=max(nums[i],nums[i]+dp[i-1]);
        //     mx=max(dp[i],mx);
        // }
        // return mx;
    }
};
