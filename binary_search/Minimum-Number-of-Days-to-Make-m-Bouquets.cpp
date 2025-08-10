class Solution {
public:
    bool chck(vector<int>& v, int day, int m, int k) {
        int b = 0, f = 0;
        for (int i : v) {
            if (i <= day) {
                f++;
                if (f == k) {
                    b++;
                    f = 0;
                }
            } else
                f = 0;
        }
        return b >= m;
    }

    int minDays(vector<int>& v, int m, int k) {
        long long total = 1LL * m * k;
        if (total > v.size())
            return -1;

        int l = *min_element(v.begin(), v.end()),
            r = *max_element(v.begin(), v.end()), ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (chck(v, mid, m, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
