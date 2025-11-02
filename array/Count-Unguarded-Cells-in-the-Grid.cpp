class Solution {
public:
    int countUnguarded(int R, int C, vector<vector<int>>& gs,
                       vector<vector<int>>& ws) {
        int res = 0;
        vector<vector<char>> g(R, vector<char>(C)), L(R, vector<char>(C)),
            Rt(R, vector<char>(C)), U(R, vector<char>(C)),
            D(R, vector<char>(C));

        for (auto& p : gs)
            g[p[0]][p[1]] = 'G';
        for (auto& p : ws)
            g[p[0]][p[1]] = 'W';

        for (int i = 0; i < R; ++i) {
            char lc = 0;
            for (int j = 0; j < C; ++j)
                rf(g[i][j], lc, L[i][j]);
            lc = 0;
            for (int j = C - 1; j >= 0; --j)
                rf(g[i][j], lc, Rt[i][j]);
        }

        for (int j = 0; j < C; ++j) {
            char lc = 0;
            for (int i = 0; i < R; ++i)
                rf(g[i][j], lc, U[i][j]);
            lc = 0;
            for (int i = R - 1; i >= 0; --i)
                rf(g[i][j], lc, D[i][j]);
        }

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (g[i][j] == 0 && L[i][j] != 'G' && Rt[i][j] != 'G' &&
                    U[i][j] != 'G' && D[i][j] != 'G')
                    ++res;

        return res;
    }

private:
    void rf(char c, char& lc, char& ic) {
        if (c == 'G' || c == 'W')
            lc = c;
        else
            ic = lc;
    }
};
