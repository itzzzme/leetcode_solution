class Solution {
public:
    vector<int> dp;
    // memoization + recursion
    // int solve(vector<int>& v, int i) {
    //     if (i >= v.size())
    //         return 0;
    //     if (dp[i] != -1)
    //         return dp[i];
    //     int take = v[i] + solve(v, i + 2);
    //     int skip = solve(v, i + 1);
    //     return dp[i] = max(take, skip);
    // }
    int rob(vector<int>& v) {
        if (v.size() == 0)
            return 0;
        if (v.size() == 1)
            return v[0];
        dp.resize(v.size(), -1);
        dp[0] = v[0];
        dp[1] = max(v[1], v[0]);
        for (int i = 2; i < v.size(); i++) {
            dp[i] = max(v[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[v.size() - 1];
    }
};