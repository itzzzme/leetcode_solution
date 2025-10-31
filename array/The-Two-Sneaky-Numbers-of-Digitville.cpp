class Solution {
public:
    vector<int> getSneakyNumbers(const vector<int>& nums) {
        vector<int> ans, cnt(101);

        for (auto i : nums)
            if (++cnt[i] == 2)
                ans.push_back(i);

        return ans;
    }
};