class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> mxdp(n);
        vector<int> mndp(n);

        mxdp[0] = nums[0];
        mndp[0] = nums[0];

        int result = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] >= 0) {
                mxdp[i] = max(nums[i], mxdp[i-1] * nums[i]);
                mndp[i] = min(nums[i], mndp[i-1] * nums[i]);
            } else {
                mxdp[i] = max(nums[i], mndp[i-1] * nums[i]);
                mndp[i] = min(nums[i], mxdp[i-1] * nums[i]);
            }

            result = max(result, mxdp[i]);
        }

        return result;
    }
};
