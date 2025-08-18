class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(vector<int>& nums, int i, bool even) {
        if (i >= nums.size()) return 0;
        if (dp[i][even] != -1) return dp[i][even];
        long long skip = solve(nums, i + 1, even);
        long long take;
        if (even)
            take = nums[i] + solve(nums, i + 1, !even);
        else
            take = -nums[i] + solve(nums, i + 1, !even);
        return dp[i][even] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<long long>(2, -1));
        return solve(nums, 0, true);  
    }
};
