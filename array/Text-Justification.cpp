class Solution {
public:
    vector<string> fullJustify(vector<string>& w, size_t W) {
        vector<string> out, row;
        size_t letters = 0;

        for (auto& x : w) {
            if (letters + row.size() + x.size() > W) {
                size_t sp = W - letters;
                if (row.size() == 1)
                    row[0].append(sp, ' ');
                else
                    for (size_t i = 0; i < sp; ++i)
                        row[i % (row.size() - 1)] += ' ';
                out.push_back(J(row, ""));
                row.clear();
                letters = 0;
            }
            row.push_back(x);
            letters += x.size();
        }
        out.push_back(L(J(row, " "), W));
        return out;
    }

private:
    static string J(const vector<string>& a, const string& sep) {
        string s;
        for (size_t i = 0; i < a.size(); ++i) {
            s += a[i];
            if (i + 1 < a.size())
                s += sep;
        }
        return s;
    }
    static string L(string s, size_t w) {
        if (s.size() < w)
            s.append(w - s.size(), ' ');
        return s;
    }
};
