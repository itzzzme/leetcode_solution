class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 1, r = num ;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (mid * mid == num)
                return true;
            if (mid * mid < num)
                l = mid + 1;
            if (mid * mid > num)
                r = mid - 1;
        }
        return false;
    }
};