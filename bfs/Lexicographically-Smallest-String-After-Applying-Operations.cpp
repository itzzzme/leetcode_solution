class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {

        auto applyA = [&](string& str) {
            for (int i = 1; i < str.size(); i += 2) {
                str[i] = ((str[i] - '0' + a) % 10) + '0';
            }
        };

        set<string> seen;
        queue<string> q;
        q.push(s);
        seen.insert(s);

        string ans = s;

        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            ans = min(ans, cur);
            string modified = cur;
            applyA(modified);
            if (seen.find(modified) == seen.end()) {
                seen.insert(modified);
                q.push(modified);
            }
            string rotated =
                cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (seen.find(rotated) == seen.end()) {
                seen.insert(rotated);
                q.push(rotated);
            }
        }

        return ans;
    }
};
