class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        vector<string> v;
        string temp;
        for (char c : s) {
            if (c == ' ') {
                if (!temp.empty()) {
                    v.push_back(temp);
                    temp.clear();
                }
            } else {
                temp += c;
            }
        }
        if (!temp.empty())
            v.push_back(temp);
        if (v.size() != pattern.size())
            return false;
        for (int i = 0; i < pattern.size(); i++) {
            char p = pattern[i];
            string w = v[i];
            if (charToWord.count(p)) {
                if (charToWord[p] != w)
                    return false;
            } else {
                charToWord[p] = w;
            }
            if (wordToChar.count(w)) {
                if (wordToChar[w] != p)
                    return false;
            } else {
                wordToChar[w] = p;
            }
        }

        return true;
    }
};
