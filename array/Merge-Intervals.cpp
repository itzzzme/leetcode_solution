class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b){
                 return a[0] < b[0];
             });

        vector<vector<int>> v;
        vector<int> current = intervals[0];

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= current[1]) {
                current[1] = max(current[1], intervals[i][1]);
            } else {
                v.push_back(current);
                current = intervals[i];
            }
        }
        v.push_back(current);
        return v;
    }
};
