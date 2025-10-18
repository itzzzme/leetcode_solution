class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long occupied = LLONG_MIN / 4;
        int ans = 0;
        for (long long x : nums) {
            long long L = x - (long long)k;
            long long R = x + (long long)k;
            long long cur = max(occupied + 1, L);
            if (cur <= R) {
                ans++;
                occupied = cur;
            }
        }
        return ans;
    }
};