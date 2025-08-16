class Solution {
public:
    int findLHS(vector<int>& v) {
        sort(v.begin(), v.end());
        int l = 0, ans = 0;
        for (int r = 0; r < v.size(); r++) {
            while (v[r] - v[l] > 1) 
                l++;
            if (v[r] - v[l] == 1) 
                ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
