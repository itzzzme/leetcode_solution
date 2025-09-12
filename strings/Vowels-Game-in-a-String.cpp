class Solution {
public:
    bool doesAliceWin(string s) {
        string v = "aeiou";
        for (char c : s) {
            if (v.find(c) != string::npos) {
                return true;
            }
        }
        return false;
    }
};