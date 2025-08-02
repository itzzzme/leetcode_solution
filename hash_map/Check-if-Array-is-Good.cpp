class Solution {
public:
    bool isGood(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        set<int> s;
        for (auto i : nums) {
            s.insert(i);
            mp[i]++;
        }
        if (mp[mx] != 2 or nums.size() != mx + 1 or s.size()!=mx)
            return false;
        return true;
    }
};