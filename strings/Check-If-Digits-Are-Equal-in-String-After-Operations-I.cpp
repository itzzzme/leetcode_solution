class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int> v;
        for (char c : s)
            v.push_back(c - '0');

        while (v.size() > 2) {
            vector<int> next;
            for (int i = 0; i + 1 < v.size(); ++i) {
                next.push_back((v[i] + v[i + 1]) % 10);
            }
            v = move(next);
        }

        return v[0] == v[1];
    }
};