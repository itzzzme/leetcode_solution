1class Solution {
2 public:
3  int minOperations(vector<int>& nums, int k) {
4    return accumulate(nums.begin(), nums.end(), 0) % k;
5  }
6};