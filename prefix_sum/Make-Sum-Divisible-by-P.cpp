1class Solution {
2public:
3    int minSubarray(vector<int>& a, int p) {
4        long s = accumulate(a.begin(), a.end(), 0L);
5        int r = s % p;
6        if (r == 0)
7            return 0;
8
9        unordered_map<int, int> mp{{0, -1}};
10        int pref = 0, n = a.size(), ans = n;
11
12        for (int i = 0; i < n; ++i) {
13            pref = (pref + a[i]) % p;
14            int need = (pref - r + p) % p;
15            if (mp.count(need))
16                ans = min(ans, i - mp[need]);
17            mp[pref] = i;
18        }
19        return ans == n ? -1 : ans;
20    }
21};
22