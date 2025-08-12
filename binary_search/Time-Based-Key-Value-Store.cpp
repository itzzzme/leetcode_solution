class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";
        auto &arr = mp[key];
        int l = 0, r = arr.size() - 1;
        string res = "";
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid].first <= timestamp) {
                res = arr[mid].second; 
                l = mid + 1;           
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
