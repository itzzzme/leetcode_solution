class Solution {
public:
    bool check(vector<int>& v, int dist, int cows) {
        int cnt = 1, last = v[0];
        int n = v.size();
        for (int i = 1; i < n; i++)
            if (v[i] - last >= dist) {
                cnt++;
                last = v[i];
                if (cnt >= cows)
                    return true;
            }
        return false;
    }
    int maxDistance(vector<int>& v, int m) {
        sort(v.begin(), v.end());
        int n = v.size();
        int l=0, r = v[n - 1] - v[0], ans = -1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(!check(v,mid,m))
                r=mid-1;
            else {
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
};