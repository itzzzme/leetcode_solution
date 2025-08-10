class Solution {
public:
    bool chck(vector<int>& v, int m, int days) {
        int sum = 0, cnt = 1;
        for (int i : v) {
            if (sum + i > m) {
                cnt++;      
                sum = 0;     
            }
            sum += i;
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& v, int days) {
        int l = *max_element(v.begin(), v.end()),
            r = accumulate(v.begin(), v.end(), 0), ans = l;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (chck(v, mid, days)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};