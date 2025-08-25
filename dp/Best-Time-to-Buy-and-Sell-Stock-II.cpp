class Solution {
public:
    int solve(vector<int> &v, int i, bool bought, vector<vector<int>>& dp) {
        if (i == v.size()) return 0;
        if (dp[i][bought] != -1) return dp[i][bought];
        int profit = 0;
        if (bought) {
            int sell = v[i] + solve(v, i + 1, false, dp);
            int hold = solve(v, i + 1, true, dp);
            profit = max(sell, hold);
        } else {
            int buy = -v[i] + solve(v, i + 1, true, dp);
            int skip = solve(v, i + 1, false, dp); 
            profit = max(buy, skip);
        }

        return dp[i][bought] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, false, dp);
    }
};
