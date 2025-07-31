class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for (auto i : nums)
            mp[i]++;
        for (auto i : mp)
            if (i.second > floor(nums.size() / 2))
                return i.first;
        return 0;
    }
};