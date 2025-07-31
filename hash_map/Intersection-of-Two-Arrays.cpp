class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> temp1(nums1.begin(),nums1.end());
        set<int> temp2(nums2.begin(),nums2.end());
        unordered_map<int,int> mp1,mp2;
        vector<int> res;
        for(auto i:temp1) mp1[i]++;
        for(auto i:temp2) mp2[i]++;
        for(auto i:mp1)
            if(mp2[i.first]) res.push_back(i.first);
        return res;
    }
};