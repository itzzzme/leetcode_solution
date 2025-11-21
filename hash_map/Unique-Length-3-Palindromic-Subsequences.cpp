class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(), r = 0;
        vector<int> f(26, n), l(26, -1);

        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            f[c] = min(f[c], i);
            l[c] = i;
        }

        for (int c = 0; c < 26; ++c)
            if (f[c] < l[c])
                r += unordered_set<char>(s.begin() + f[c] + 1, s.begin() + l[c])
                         .size();

        return r;
    }
};
