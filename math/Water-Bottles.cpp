class Solution {
public:
    int numWaterBottles(int n, int k) {
        int total = n;
        while (n >= k) {
            int temp = n / k;
            total += temp;
            n = n % k + temp;
        }
        return total;
    }
};
