#define ll long long
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        if (m == 0 || n == 0) return 0;
        vector<ll> pref(n+1,0);
        for (int i=0;i<n;i++) pref[i+1]=pref[i]+skill[i];
        vector<ll> s(m,0);
        for (int j=1;j<m;j++){
            ll mx = LLONG_MIN;
            for (int i=0;i<n;i++){
                ll val = (ll)mana[j-1]*pref[i+1] - (ll)mana[j]*pref[i];
                if (val>mx) mx=val;
            }
            if (mx < 0) mx = 0;
            s[j] = s[j-1] + mx;
        }
        ll total = pref[n];
        ll ans = 0;
        for (int j=0;j<m;j++){
            ans = max(ans, s[j] + (ll)mana[j]*total);
        }
        return ans;
    }
};