1class Solution {
2public:
3    long long maxSubarraySum(vector<int>& a, int k) {
4        long long r = LLONG_MIN, p = 0;
5        vector<long long> m(k, LLONG_MAX / 2);
6        m[k - 1] = 0;
7        for (int i = 0; i < a.size(); ++i)
8            p += a[i], r = max(r, p - m[i % k]), m[i % k] = min(m[i % k], p);
9        return r;
10    }
11};
12