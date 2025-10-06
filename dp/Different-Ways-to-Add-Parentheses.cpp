class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> result;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left = diffWaysToCompute(s.substr(0, i));
                vector<int> right = diffWaysToCompute(s.substr(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        if (s[i] == '+') result.push_back(l + r);
                        else if (s[i] == '-') result.push_back(l - r);
                        else if (s[i] == '*') result.push_back(l * r);
                    }
                }
            }
        }
        if (result.empty()) result.push_back(stoi(s));
        return result;
    }
};
