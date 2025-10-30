class Solution {
public:
    int minNumberOperations(vector<int>& v) {
        int ans = v.front();
        for (int i = 1; i < v.size(); ++i)
            if (v[i] > v[i - 1])
                ans += v[i] - v[i - 1];

        return ans;
    }
};