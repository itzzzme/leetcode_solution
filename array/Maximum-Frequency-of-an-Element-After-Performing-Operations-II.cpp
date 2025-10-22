class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = 1;
        int adjustable = 0;
        unordered_map<int, int> count;
        map<int, int> line;
        set<int> s;

        for (const int num : nums) {
            ++count[num];
            ++line[num - k];
            --line[num + k + 1];
            s.insert(num);
            s.insert(num - k);
            s.insert(num + k + 1);
        }

        for (const int num : s) {
            adjustable += line.contains(num) ? line[num] : 0;
            const int cnt = count.contains(num) ? count[num] : 0;
            const int adjusted = adjustable - cnt;
            ans = max(ans, cnt + min(numOperations, adjusted));
        }

        return ans;
    }
};