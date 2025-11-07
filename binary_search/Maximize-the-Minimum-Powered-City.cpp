class Solution {
 public:
  long long maxPower(vector<int>& s, int r, int k) {
    long l = *min_element(s.begin(), s.end());
    long h = accumulate(s.begin(), s.end(), 0L) + k + 1;
    while (l < h) {
      long m = (l + h) / 2;
      if (ok(s, r, k, m)) l = m + 1;
      else h = m;
    }
    return l - 1;
  }

 private:
  bool ok(vector<int> s, int r, int k, long m) {
    int n = s.size();
    long p = accumulate(s.begin(), s.begin() + r, 0L);
    for (int i = 0; i < n; ++i) {
      if (i + r < n) p += s[i + r];
      if (p < m) {
        long need = m - p;
        if (need > k) return false;
        s[min(n - 1, i + r)] += need;
        k -= need;
        p += need;
      }
      if (i - r >= 0) p -= s[i - r];
    }
    return true;
  }
};
