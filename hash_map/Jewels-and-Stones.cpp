class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<int, int> mp;
        for (auto i : jewels)
            mp[i]++;
        int cnt = 0;
        for (auto i : stones)
            if (mp[i])
                cnt++;
        return cnt;
    }
};