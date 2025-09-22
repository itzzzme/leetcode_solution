class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1;
        while (hi - lo > 2) {
            int delta = (hi - lo) / 3;
            int m1 = lo + delta;
            int m2 = hi - delta;
            if (arr[m1] < arr[m2])
                lo = m1 + 1;
            else
                hi = m2 - 1;
        }
        return max_element(arr.begin() + lo, arr.begin() + hi + 1) -
               arr.begin();
    }
};
