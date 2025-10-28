class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> pref(n), suf(n);

        for (int i = 1; i < n; ++i)
            pref[i] = pref[i - 1] + nums[i - 1];

        for (int i = n - 2; i >= 0; --i)
            suf[i] = suf[i + 1] + nums[i + 1];

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                continue;
            if (pref[i] == suf[i])
                ans += 2;
            if (abs(pref[i] - suf[i]) == 1)
                ans++;
        }

        return ans;
    }
};