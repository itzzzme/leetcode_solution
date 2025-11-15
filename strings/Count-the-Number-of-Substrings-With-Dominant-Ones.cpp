class Solution {
 public:
  int numberOfSubstrings(string s) {
    int res = 0;
    for (int z = 0; z + z * z <= s.size(); ++z) {
      int last = -1;
      vector<int> cnt(2);
      for (int l = 0, r = 0; r < s.size(); ++r) {
        ++cnt[s[r] - '0'];
        for (; l < r; ++l) {
          if (s[l] == '0' && cnt[0] > z) {
            --cnt[0];
            last = l;
          } else if (s[l] == '1' && cnt[1] - 1 >= z * z) {
            --cnt[1];
          } else {
            break;
          }
        }
        if (cnt[0] == z && cnt[1] >= z * z)
          res += l - last;
      }
    }
    return res;
  }
};
