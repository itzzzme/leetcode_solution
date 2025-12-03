1class Solution {
2public:
3    vector<vector<int>> combine(int n, int k) {
4        vector<vector<int>> res;
5        vector<int> cur;
6        backtrack(1, n, k, cur, res);
7        return res;
8    }
9
10private:
11    void backtrack(int start, int n, int k, vector<int>& cur,
12                   vector<vector<int>>& res) {
13        if (cur.size() == k) {
14            res.push_back(cur);
15            return;
16        }
17        for (int i = start; i <= n; ++i) {
18            cur.push_back(i);
19            backtrack(i + 1, n, k, cur, res);
20            cur.pop_back();
21        }
22    }
23};
24