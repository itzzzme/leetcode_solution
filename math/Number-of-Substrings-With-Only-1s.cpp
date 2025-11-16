class Solution {
public:
    int numSub(string s) {
        int mod = 1e9 + 7, ans = 0, l = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                l = i;
            ans = (ans + i - l) % mod;
        }

        return ans;
    }
};