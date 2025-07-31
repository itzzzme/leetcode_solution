class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> freq;
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        set<int> s3(nums3.begin(), nums3.end());
        for (int num : s1) freq[num]++;
        for (int num : s2) freq[num]++;
        for (int num : s3) freq[num]++;
        vector<int> ans;
        for (auto& [num, count] : freq) {
            if (count >= 2) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};