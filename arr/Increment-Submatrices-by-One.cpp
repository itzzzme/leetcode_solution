class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> a(n, vector<int>(n)), p(n, vector<int>(n + 1));

        for (auto& v : q) {
            int r1 = v[0], c1 = v[1], r2 = v[2], c2 = v[3];
            for (int r = r1; r <= r2; r++) {
                p[r][c1]++;
                p[r][c2 + 1]--;
            }
        }

        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                s += p[i][j];
                a[i][j] = s;
            }
        }
        return a;
    }
};
