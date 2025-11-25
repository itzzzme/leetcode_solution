class Solution {
public:
  int smallestRepunitDivByK(int k) {
    if (k % 2 == 0 || k % 5 == 0) return -1;

    unordered_set<int> s;
    int r = 0;

    for (int i = 1; i <= k; ++i) {
      r = (r * 10 + 1) % k;
      if (r == 0) return i;
      if (s.count(r)) return -1;
      s.insert(r);
    }
    return -1;
  }
};
