class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        int count = freq.begin()->second;
        for (const auto& [key, value] : freq) {
            if (value != count)
                return false;
        }
        return true;
    }
};