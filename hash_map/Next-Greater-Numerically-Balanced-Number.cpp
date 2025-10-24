class Solution {
public:
    int nextBeautifulNumber(int n) {
        while (!check(++n))
            ;
        return n;
    }

private:
    bool check(int num) {
        vector<int> cnt(10);
        while (num > 0) {
            if (num % 10 == 0)
                return false;
            ++cnt[num % 10];
            num /= 10;
        }
        for (int i = 1; i < 10; ++i)
            if (cnt[i] && cnt[i] != i)
                return false;
        return true;
    }
};