class Solution {
public:
    // vector<vector<long long>> dp;
    // memoization + recursion
    // long long solve(vector<int>& nums, int i, bool even) {
    //     if (i >= nums.size()) return 0;
    //     if (dp[i][even] != -1) return dp[i][even];
    //     long long skip = solve(nums, i + 1, even);
    //     long long take;
    //     if (even)
    //         take = nums[i] + solve(nums, i + 1, !even);
    //     else
    //         take = -nums[i] + solve(nums, i + 1, !even);
    //     return dp[i][even] = max(skip, take);
    // }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // bottom-up approach
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][1] - nums[i - 1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + nums[i - 1], dp[i - 1][1]);
        }
        return max(dp[n][0], dp[n][1]);
        // return solve(nums, 0, true);
    }
};
