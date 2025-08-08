#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool chck(vector<int> &v, int n, int h) {
        int timer = 0;
        for (auto i : v) {
            if (timer > h) return false;
            if (i <= n) timer++;
            else timer += (i + n - 1) / n; 
        }
        return timer <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (chck(piles, mid, h)) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
