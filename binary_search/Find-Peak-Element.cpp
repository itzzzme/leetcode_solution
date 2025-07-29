class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        if (nums.size() == 1)
            return 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid > 0 and mid < n - 1 and nums[mid] > nums[mid - 1] and
                nums[mid] > nums[mid + 1]) {
                return mid;
            } else if ((mid == 0 and nums[0] > nums[1]) or
                       (mid == n - 1 and nums[n - 1] > nums[n - 2]))
                return mid;
            else if (mid > 0 and nums[mid] < nums[mid - 1])
                r = mid - 1;
            else if (mid < n - 1 and nums[mid] < nums[mid + 1])
                l = mid + 1;
        }
        return -1;
    }
};