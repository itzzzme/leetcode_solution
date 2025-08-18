class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& v, int pidx, int i) {
        if (i == v.size())
            return 0;
        int take = 0;
        if (dp[i][pidx + 1] != -1)
            return dp[i][pidx + 1];
        if (pidx == -1 or v[i] > v[pidx]) {
            take = 1 + solve(v, i, i + 1);
        }
        int skip = solve(v, pidx, i + 1);
        return dp[i][pidx + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return solve(nums, -1, 0);
    }
};
