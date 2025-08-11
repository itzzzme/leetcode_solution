class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // brue force approach will be to iterate throuhg all elements in the
        // matrix whose time complexity will be O(m*n)

        vector<int> v;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> new_mat(n + 2, vector<int>(m + 2, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                new_mat[i + 1][j + 1] = mat[i][j];
            }
        }
        for (int i = 1; i <= new_mat.size() - 2; i++) {
            for (int j = 1; j <= new_mat[0].size() - 2; j++) {
                int curr = new_mat[i][j], left = new_mat[i][j - 1],
                    top = new_mat[i - 1][j], down = new_mat[i + 1][j],
                    right = new_mat[i][j + 1];
                if (curr > left and curr > top and curr > down and
                    curr > right) {
                    v.push_back(i - 1);
                    v.push_back(j - 1);
                    return v;
                }
            }
        }
        return v;
    }
};