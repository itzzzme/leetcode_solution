class Solution {
public:
    char findTheDifference(string s, string t) {
        string total = s + t;
        char c = total[0];
        for(int i=1;i<total.size();i++) c^=total[i];
        return c;
    }
};