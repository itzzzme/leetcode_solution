class Solution {
public:
  vector<long long> findXSum(vector<int>& a, int k, int x) {
    vector<long long> res;
    long long ws = 0;
    unordered_map<int,int> cnt;
    multiset<pair<int,int>> hi, lo;

    auto upd = [&](int v, int d) {
      if (cnt[v] > 0) {
        if (auto it = lo.find({cnt[v], v}); it != lo.end()) lo.erase(it);
        else if (auto it2 = hi.find({cnt[v], v}); it2 != hi.end()) {
          hi.erase(it2);
          ws -= 1LL * v * cnt[v];
        }
      }
      cnt[v] += d;
      if (cnt[v] > 0) lo.insert({cnt[v], v});
    };

    for (int i = 0; i < (int)a.size(); ++i) {
      upd(a[i], 1);
      if (i >= k) upd(a[i - k], -1);

      while (!lo.empty() && hi.size() < (size_t)x) {
        auto [c, v] = *prev(lo.end());
        lo.erase(prev(lo.end()));
        hi.insert({c, v});
        ws += 1LL * v * c;
      }
      while (!lo.empty() && !hi.empty() && *prev(lo.end()) > *hi.begin()) {
        auto [cb, vb] = *prev(lo.end());
        auto [ch, vh] = *hi.begin();
        lo.erase(prev(lo.end()));
        hi.erase(hi.begin());
        lo.insert({ch, vh});
        hi.insert({cb, vb});
        ws += 1LL * vb * cb - 1LL * vh * ch;
      }
      if (i >= k - 1) res.push_back(ws);
    }
    return res;
  }
};
