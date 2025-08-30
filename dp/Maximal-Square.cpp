class Solution {
public:
    int maximalSquare(vector<vector<char>>& v) {
        int n = v.size(), m = v[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int res = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == '1'){
                    int mx = min({dp[i][j+1], dp[i+1][j], dp[i][j]});
                    dp[i+1][j+1] = mx + 1;
                    res = max(res, dp[i+1][j+1]);
                } else {
                    dp[i+1][j+1] = 0;
                }
            }
        }

        return res * res;
    }
};
