class Solution {
public:
    int retOne(const string& num) {
        int one = 0;
        for (char c : num) {
            one += (c == '1');
        }
        return one;
    }

    int retZero(const string& num) {
        int zero = 0;
        for (char c : num) {
            zero += (c == '0');
        }
        return zero;
    }

    // recursive approach
    // vector<vector<vector<int>>> memo;

    // int solve_dp(int i, int m, int n, vector<string>& v) {
    //     if (i == v.size()) {
    //         return 0; 
    //     }
    //     if (memo[i][m][n] != -1) {
    //         return memo[i][m][n];
    //     }
    //     int zeros = retZero(v[i]);
    //     int ones = retOne(v[i]);

    //     int skip = solve_dp(i + 1, m, n, v);
    //     int take = 0;
    //     if (zeros <= m && ones <= n) {
    //         take = 1 + solve_dp(i + 1, m - zeros, n - ones, v); 
    //     }
    //     return memo[i][m][n] = max(take, skip);
    // }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // memo.resize(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        
        // return solve_dp(0, m, n, strs);

        // iterative approach
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (const string& str : strs) {
            int ones = retOne(str);
            int zeros = retZero(str);

            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        return dp[m][n];
    }
};
