class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, one = 0;

        for (int i = 0; i < s.length(); ++i)
            if (s[i] == '1')
                ++one;
            else if (i + 1 == s.length() or s[i + 1] == '1')
                ans += one;

        return ans;
    }
};