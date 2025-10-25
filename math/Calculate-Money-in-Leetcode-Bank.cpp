class Solution {
public:
    int totalMoney(int n) {
        int w = n / 7;
        int f_w = f(1, 7);
        int lf_w = f(1 + w - 1, 7 + w - 1);
        int rem = f(1 + w, n % 7 + w);
        return (f_w + lf_w) * w / 2 + rem;
    }

    int f(int a, int b) { return (a + b) * (b - a + 1) / 2; }
};