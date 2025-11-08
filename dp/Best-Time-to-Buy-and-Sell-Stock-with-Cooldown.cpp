class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = 0, hold = INT_MIN, prev = 0;

        for (auto i : prices) {
            const int cache = sell;
            sell = max(sell, hold + i);
            hold = max(hold, prev - i);
            prev = cache;
        }

        return sell;
    }
};