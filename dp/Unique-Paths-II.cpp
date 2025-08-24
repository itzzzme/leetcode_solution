class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& v, int i, int j) {
        if (i >= (int)v.size() or j >= (int)v[0].size() or v[i][j] == 1)
            return 0;
        if (i == (int)v.size() - 1 and j == (int)v[0].size() - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = solve(v, i + 1, j) + solve(v, i, j + 1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return solve(v, 0, 0);
    }
};