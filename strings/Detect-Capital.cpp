class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size(), lower = 0, cap = 0, cap_first = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 and word[i] >= 'A' and word[i] <= 'Z')
                cap_first = 1;
            if (word[i] >= 'a' and word[i] <= 'z')
                lower++;
            else
                cap++;
        }
        return (lower == n or cap == n or (cap_first == 1 and lower == n - 1));
    }
};