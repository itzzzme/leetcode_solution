class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),j = matrix[0].size();
        if (!n or !j) return false;
        int l = 0, r = n * j - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midVal = matrix[mid / j][mid % j]; 
            if (midVal == target) return true;
            else if (midVal < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
