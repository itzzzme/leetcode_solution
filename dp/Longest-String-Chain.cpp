class Solution {
public:
    // memoization + recursion
    // vector<vector<int>> dp;
    bool chck(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        if (m > n)
            return false;
        int i = 0, j = 0;
        while (i < m and j < n) {
            if (s1[i] == s2[j])
                i++;
            j++;
        }
        return i == m;
    }
    // int solve(vector<string>& v, int i, int prev) {
    //     if (i == v.size())
    //         return 0;
    //     if (dp[i][prev + 1] != -1)
    //         return dp[i][prev + 1];
    //     int take = 0;
    //     if (prev == -1 or (chck(v[prev], v[i]) and
    //                        abs((int)v[prev].size() - (int)v[i].size()) == 1))
    //         take = 1 + solve(v, i + 1, i);
    //     int skip = solve(v, i + 1, prev);
    //     return dp[i][prev + 1] = max(take, skip);
    // }
    int longestStrChain(vector<string>& v) {
        int n = v.size();
        // dp.assign(n, vector<int>(n + 1, -1));
        sort(v.begin(), v.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        // bottom-up approach
        int mx = 1;
        vector<int> dp(n + 1, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (chck(v[j], v[i]) and
                    abs((int)v[j].size() - (int)v[i].size()) == 1) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    mx = max(dp[i], mx);
                }
            }
        }
        return mx;
        // return solve(v, 0, -1);
    }
};