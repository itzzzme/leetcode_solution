class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        int ans = 0;
        bool chck = false;
        for (auto& [ch, count] : mp) {
            ans += (count / 2) * 2; 
            if (count % 2 == 1)
                chck = true;
        }
        if (chck)
            ans += 1;
        return ans;
    }
};
