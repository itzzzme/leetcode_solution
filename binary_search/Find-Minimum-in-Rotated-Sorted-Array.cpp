class Solution {
public:
    int findMin(vector<int>& v) {
        int l = 0, r = v.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (v[mid] < v[r])
                r = mid;
            else if (v[mid] > v[r])
                l = mid + 1;
            else
                r--;
        }
        return v[l];
    }
};