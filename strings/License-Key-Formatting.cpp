class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        int count = 0;

        for (char c : s) 
            if (c != '-')
                result += toupper(c);

        int len = result.length();
        int fi = len % k == 0 ? k : len % k;

        string ans = result.substr(0, fi);

        for (int i = fi; i < len; i += k) 
            ans += '-' + result.substr(i, k);
        return ans;
    }
};
