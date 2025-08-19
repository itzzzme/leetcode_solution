class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& v, int prev, int i) {
        if (i >= v.size())
            return 0;
        int take = 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        if (prev == -1 or v[i][0] > v[prev][1])
            take = 1 + solve(v, i, i + 1);
        int skip = solve(v, prev, i + 1);
        return dp[i][prev + 1] = max(take, skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        dp.assign(n, vector<int>(n + 1, -1));
        sort(pairs.begin(), pairs.end());
        return solve(pairs, -1, 0);
    }
};