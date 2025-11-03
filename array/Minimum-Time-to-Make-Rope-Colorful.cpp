class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int ans = 0;
        int n = s.size();
        int maxCost = v[0];  
        
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) {
                ans += min(maxCost, v[i]);
                maxCost = max(maxCost, v[i]);
            } else {
                maxCost = v[i];
            }
        }
        return ans;
    }
};
