class Solution {
public:
    // vector<vector<int>> dp;
    // memoization + recursion
    // int solve(vector<vector<int>>& v, int prev, int i) {
    //     if (i >= v.size())
    //         return 0;
    //     int take = 0;
    //     if (dp[i][prev + 1] != -1)
    //         return dp[i][prev + 1];
    //     if (prev == -1 or v[i][0] > v[prev][1])
    //         take = 1 + solve(v, i, i + 1);
    //     int skip = solve(v, prev, i + 1);
    //     return dp[i][prev + 1] = max(take, skip);
    // }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        // dp.assign(n, vector<int>(n + 1, -1));
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        // bottom-up approach
        int mx = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    mx = max(dp[i], mx);
                }
            }
        }
        // return solve(pairs, -1, 0);
        return mx;
    }
};