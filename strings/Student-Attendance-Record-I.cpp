class Solution {
public:
    bool checkRecord(string s) {
        int A = 0, mx = 0, cnt = 0;
        for (char c : s) {
            if (c == 'L') {
                cnt++;
                mx = max(cnt, mx);
            } else {
                cnt = 0;
                A += (c == 'A');
            }
        }
        return (A < 2 and mx < 3);
    }
};