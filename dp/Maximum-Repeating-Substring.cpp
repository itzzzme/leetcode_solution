class Solution {
public:
    int maxRepeating(string sequence, string word) {
        // int n = sequence.size();
        // int m = word.size();
        // vector<int> dp(n, 0);
        // int ans = 0;
        // for (int i = m - 1; i < n; i++) {
        //     if (sequence.substr(i - m + 1, m) == word) {
        //         if (i - m >= 0)
        //             dp[i] = dp[i - m] + 1;
        //         else
        //             dp[i] = 1;
        //         ans = max(ans, dp[i]);
        //     }
        // }
        // return ans;

        // simple approach without dp
        string temp = word;
        int cnt = 0;
        while (sequence.find(temp) != string::npos) {
            cnt++;
            temp += word; 
        }
        return cnt;
    }
};
