1class Solution {
2public:
3    long long maxRunTime(int n, vector<int>& b) {
4        long long s = accumulate(b.begin(), b.end(), 0LL);
5        sort(b.begin(), b.end());
6        while (b.back() > s / n) {
7            s -= b.back();
8            b.pop_back();
9            --n;
10        }
11        return s / n;
12    }
13};
14