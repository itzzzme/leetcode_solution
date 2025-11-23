class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3);

        for (auto i : nums)
            for (auto j : vector<int>(dp))
                dp[(j + i) % 3] = max(dp[(j + i) % 3], j + i);

        return dp[0];
    }
};