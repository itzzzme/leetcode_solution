class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        unordered_set<int> cols, diag1, diag2;
        backtrack(0, n, result, cols, diag1, diag2);
        return result;
    }

private:
    void backtrack(int row, int n, int& result, unordered_set<int>& cols,
                   unordered_set<int>& diag1, unordered_set<int>& diag2) {
        if (row == n) {
            result++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols.count(col) || diag1.count(row - col) ||
                diag2.count(row + col)) {
                continue;
            }

            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            backtrack(row + 1, n, result, cols, diag1, diag2);

            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }
};
