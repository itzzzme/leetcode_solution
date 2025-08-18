class Solution {
public:

    // memoization + recursion (Top-Down)
    int solve(vector<int>& v, int i, int size, vector<int>& dp) {
        if (i >= size)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int take = v[i] + solve(v, i + 2, size, dp);
        int skip = solve(v, i + 1, size, dp);
        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& v) {
        int n = v.size();
        if (n == 0)
            return 0;
        if (n <= 3)
            return *max_element(v.begin(), v.end());
        // vector<int> dp1(n, -1);
        // vector<int> dp2(n, -1);
        // return max(solve(v, 0, n - 1, dp1), solve(v, 1, n, dp2));

        // bottom-up approach
        vector<int> dp(n - 1, -1);
        dp[0] = v[0];
        dp[1] = max(v[1], v[0]);
        for (int i = 2; i < n - 1; i++)
            dp[i] = max(v[i] + dp[i - 2], dp[i - 1]);
        int d1 = dp[n - 2];
        dp.clear();
        dp.assign(n - 1, -1);
        dp[0] = v[1];
        dp[1] = max(v[1], v[2]);
        for (int i = 3; i < n; i++)
            dp[i - 1] = max(v[i] + dp[i -3], dp[i - 2]);
        int d2 = dp[n - 2];
        return max(d1, d2);
    }
};
