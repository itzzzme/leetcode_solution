class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size(), n2 = nums2.size();
        int total = n1 + n2;
        int half = (total + 1) / 2;
        int l = 0, r = n1;
        while (l <= r) {
            int px = l + (r - l) / 2;
            int py = half - px;
            int maxlX = (px == 0) ? INT_MIN : nums1[px - 1];
            int minrX = (px == n1) ? INT_MAX : nums1[px];
            int maxlY = (py == 0) ? INT_MIN : nums2[py - 1];
            int minrY = (py == n2) ? INT_MAX : nums2[py];
            if (maxlX <= minrY && maxlY <= minrX) {
                if (total % 2 == 0) {
                    return (max(maxlX, maxlY) + min(minrX, minrY)) / 2.0;
                } else {
                    return max(maxlX, maxlY);
                }
            } 
            else if (maxlX > minrY) {
                r = px - 1;
            } else {
                l = px + 1;
            }
        }
        return 0.0; 
    }
};
