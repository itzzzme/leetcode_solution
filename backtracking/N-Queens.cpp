class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        set<int> columns, diag1, diag2;
        backtrack(result, board, 0, n, columns, diag1, diag2);
        return result;
    }

private:
    void backtrack(vector<vector<string>>& result, vector<string>& board,
                   int row, int n, set<int>& columns, set<int>& diag1,
                   set<int>& diag2) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (columns.count(col) || diag1.count(row - col) ||
                diag2.count(row + col)) {
                continue;
            }

            board[row][col] = 'Q';
            columns.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            backtrack(result, board, row + 1, n, columns, diag1, diag2);

            board[row][col] = '.';
            columns.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }
};
