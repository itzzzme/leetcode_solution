class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n+1,0);
        for(auto i:bookings){
            for(int j=i[0];j<=i[1];j++)
                v[j]+=i[2];
        }
        vector<int> ans;
        for(int i=1;i<=n;i++)
            ans.push_back(v[i]);
        return ans;
    }
};