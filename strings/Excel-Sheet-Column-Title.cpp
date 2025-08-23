class Solution {
public:
    string convertToTitle(int c) {
        string s = "";
        while (c > 0) {
            c--;  
            char ch = 'A' + (c % 26);
            s = ch + s;  
            c /= 26;
        }
        return s;
    }
};
