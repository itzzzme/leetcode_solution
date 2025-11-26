1#define vti vector<int>
2#define vvti vector<vti>
3const int MOD = 1e9 + 7;
4
5class Solution {
6    int dfs(const vvti& g, int r, int c, int rem, int k, vector<vvti>& dp) {
7
8        int R = g.size(), C = g[0].size();
9        if (r == R or c == C)
10            return 0;
11        if (r == R - 1 and c == C - 1)
12            return ((rem + g[r][c]) % k == 0);
13
14        if (dp[r][c][rem] != -1)
15            return dp[r][c][rem];
16
17        int nxt = (rem + g[r][c]) % k;
18        return dp[r][c][rem] = (dfs(g, r + 1, c, nxt, k, dp) +
19                                dfs(g, r, c + 1, nxt, k, dp)) %
20                               MOD;
21    }
22
23public:
24    int numberOfPaths(vvti& g, int k) {
25        int R = g.size(), C = g[0].size();
26        vector<vvti> dp(R, vvti(C, vti(k, -1)));
27        return dfs(g, 0, 0, 0, k, dp);
28    }
29};
30