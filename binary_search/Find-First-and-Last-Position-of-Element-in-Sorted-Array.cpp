class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        vector<int> res;
        int n = nums.size();
        if (n == 0)
            return {-1, -1};
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= target) {
                last = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        if (last != -1 and nums[last] != target)
                last = -1;
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                first = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        if (first != -1 and nums[first] != target)
            first = -1;
        res.push_back(first);
        res.push_back(last);
        return res;
    }
};