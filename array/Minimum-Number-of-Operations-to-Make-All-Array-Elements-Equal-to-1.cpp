class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ones = ranges::count(nums, 1);
        if (ones)
            return n - ones;
        int mn = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    mn = min(mn, j - i);
                    break;
                }
            }
        }
        return mn == INT_MAX ? -1 : mn + n - 1;
    }
};
