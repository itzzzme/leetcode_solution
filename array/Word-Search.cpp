class Solution {
public:
    int n, m;
    string target;

    bool dfs(vector<vector<char>>& board, int i, int j, int index) {

        if (index == target.size()) {
            return true;
        }

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != target[index]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board, i + 1, j, index + 1) || 
                     dfs(board, i - 1, j, index + 1) || 
                     dfs(board, i, j + 1, index + 1) || 
                     dfs(board, i, j - 1, index + 1);   

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        target = word;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == target[0] && dfs(board, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};