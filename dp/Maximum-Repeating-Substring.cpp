class Solution {
public:
    int solve(const string &s, const string &target, int i) {
        if (i + target.size() > s.size()) return 0;  
        if (s.substr(i, target.size()) != target) return 0;
        return 1 + solve(s, target, i + target.size());
    }
    int maxRepeating(string sequence, string word) {
        int cnt=0;
        for(int i=0;i<sequence.size();i++){
            cnt = max(cnt, solve(sequence, word, i));
        }
        return cnt;
    }
};