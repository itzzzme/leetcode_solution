class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string temp = "";

        for (char c : s) {
            if (c == ' ') {
                if (!temp.empty()) {
                    v.push_back(temp);
                    temp = "";
                }
            } else {
                temp += c;
            }
        }

        if (!temp.empty()) {
            v.push_back(temp);
        }
        
        string ans = "";
        if (v.empty()) {
            return ""; 
        }

        for (int i = v.size() - 1; i >= 0; --i) {
            ans += v[i];
            if (i > 0) {
                ans += " ";
            }
        }

        return ans;
    }
};