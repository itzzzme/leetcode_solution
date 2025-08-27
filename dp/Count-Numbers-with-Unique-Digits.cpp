class Solution {
public:
    // solving without dp

    // int countNumbersWithUniqueDigits(int n) {
    //     if (n == 0)
    //         return 1;
    //     int res = 10, cur = 9;
    //     for (int i = 2; i <= n && i <= 10; ++i) {
    //         cur *= (11 - i);
    //         res += cur;
    //     }
    //     return res;
    // }

    // solving with dp
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        n = min(n, 10);
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 10;
        for (int i = 2; i <= n; ++i) {
            int choices = 9;
            int available = 9;
            for (int j = 1; j < i; ++j) {
                choices *= available;
                available--;
            }
            dp[i] = choices;
        }
        int result = 0;
        for (int i = 0; i <= n; ++i)
            result += dp[i];
        return --result;
    }
};
