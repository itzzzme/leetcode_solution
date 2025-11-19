class Solution {
public:
    int findFinalValue(vector<int>& nums, int org) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == org) {
                org = org * 2;
                i = -1;  
            }
            i++;
        }
        return org;
    }
};
