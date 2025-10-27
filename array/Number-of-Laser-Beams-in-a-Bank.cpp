class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0;
        for (auto i : bank) {
            int ones = ranges::count(i, '1');
            if (ones > 0) {
                ans += prev * ones;
                prev = ones;
            }
        }
        return ans;
    }
};