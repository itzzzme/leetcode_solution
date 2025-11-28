1class Solution {
2public:
3    int maxKDivisibleComponents(int n, vector<vector<int>>& e, vector<int>& val,
4                                int k) {
5        g.resize(n);
6        for (auto& x : e) {
7            g[x[0]].push_back(x[1]);
8            g[x[1]].push_back(x[0]);
9        }
10        int res = 0;
11        dfs(0, -1, val, k, res);
12        return res;
13    }
14
15private:
16    vector<vector<int>> g;
17    long dfs(int u, int p, const vector<int>& val, int k, int& res) {
18        long s = val[u];
19        for (int v : g[u])
20            if (v != p)
21                s += dfs(v, u, val, k, res);
22        if (s % k == 0)
23            ++res;
24        return s;
25    }
26};
27