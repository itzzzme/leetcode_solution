class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 0, r = n;
        while (l < r) {
            int mid = (l+r) / 2;
            // Make sure mid is even
            if (mid % 2 == 1) mid--;
            if (nums[mid] == nums[mid + 1]) 
                // Pair matched, so unique is after
                l = mid + 2;
            else 
                // Pair broke, so unique is at mid or before
                r = mid;
        }
        return nums[l];
    }
};