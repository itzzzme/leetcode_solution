class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; 1LL * i * i <= n; ++i)
            squares.push_back(i * i);

        const int INF = 1e9;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int i : squares) {
            for (int j = i; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j - i] + 1);
            }
        }

        return dp[n];
    }
};