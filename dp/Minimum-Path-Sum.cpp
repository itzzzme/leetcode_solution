class Solution {
public:
    // memoization + recursion
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& v, int i, int j) {
        if (i >= v.size() or j >= v[0].size())
            return INT_MAX;
        if (i == v.size() - 1 and j == v[0].size() - 1)
            return v[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = solve(v, i, j + 1);
        int down = solve(v, i + 1, j);

        return dp[i][j] = v[i][j] + min(right, down);
    }
    int minPathSum(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return solve(v, 0, 0);
    }
};