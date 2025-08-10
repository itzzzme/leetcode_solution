class Solution {
public:
    bool chck(const vector<int>& v, int m, int k) {
        int sum = 0;
        for (int i : v)
            sum += ceil(1.0 * i / m);
        return sum <= k;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end()), ans = l;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (chck(nums, mid, threshold)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};