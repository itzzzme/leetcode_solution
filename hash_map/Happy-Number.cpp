class Solution {
public:
    bool isHappy(int n) {
        map<int, int> mp;
        while (n > 1) {
            int sum = 0;
            if (mp[n] == 1)
                return false;
            mp[n] = 1;
            while (n > 0) {
                sum += ((n % 10) * (n % 10));
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};