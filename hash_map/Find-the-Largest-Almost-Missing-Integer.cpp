class Solution {
public:
    int largestInteger(vector<int>& v, int k) {
        int n = v.size();
        unordered_map<int, unordered_set<int>> mp;
        for (int i = 0; i <= n - k; ++i) 
            for (int j = i; j < i + k; ++j) 
                mp[v[j]].insert(i);  

        int res = -1;
        for (auto& [num, s] : mp) 
            if (s.size() == 1) 
                res = max(res, num);

        return res;
    }
};