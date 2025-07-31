class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        set<int> s(nums.begin(),nums.end());
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto i:s) mp[i]++;
        for(int i=1;i<=n;i++)
            if(!mp[i]) ans.push_back(i);
        return ans;
    }
};