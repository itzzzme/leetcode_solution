class Solution {
public:
    vector<int> findXSum(vector<int>& a, int k, int x) {
        using P = pair<int, int>;
        vector<int> res;
        long long s = 0;
        unordered_map<int, int> cnt;
        multiset<P> hi, lo;

        auto upd = [&](int v, int d) {
            if (cnt[v] > 0) {
                if (auto it = lo.find({cnt[v], v}); it != lo.end())
                    lo.erase(it);
                else {
                    auto i = hi.find({cnt[v], v});
                    hi.erase(i);
                    s -= 1LL * v * cnt[v];
                }
            }
            cnt[v] += d;
            if (cnt[v] > 0)
                lo.insert({cnt[v], v});
        };

        for (int i = 0; i < (int)a.size(); ++i) {
            upd(a[i], 1);
            if (i >= k)
                upd(a[i - k], -1);

            while (!lo.empty() && (int)hi.size() < x) {
                auto [c, v] = *prev(lo.end());
                lo.erase(prev(lo.end()));
                hi.insert({c, v});
                s += 1LL * v * c;
            }
            while (!lo.empty() && !hi.empty() &&
                   *prev(lo.end()) > *hi.begin()) {
                auto [cb, vb] = *prev(lo.end());
                auto [ch, vh] = *hi.begin();
                lo.erase(prev(lo.end()));
                hi.erase(hi.begin());
                lo.insert({ch, vh});
                hi.insert({cb, vb});
                s += 1LL * vb * cb - 1LL * vh * ch;
            }

            if (i >= k - 1)
                res.push_back((int)s);
        }
        return res;
    }
};
