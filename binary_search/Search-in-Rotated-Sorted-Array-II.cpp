class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] == nums[l] and nums[mid] == nums[r]) {
                l++;
                r--;
                continue;
            }
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target and target <= nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                if (nums[mid] <= target and target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};