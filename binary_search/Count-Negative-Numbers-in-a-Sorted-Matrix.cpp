class Solution {
public:
    int search(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid] < 0) 
                r = mid - 1;
            else 
                l = mid + 1;
        }
        return n - l;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (auto i : grid)
            ans += search(i);
        return ans;
    }
};