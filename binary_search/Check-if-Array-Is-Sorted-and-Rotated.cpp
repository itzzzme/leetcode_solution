class Solution {
public:
    bool check(vector<int>& v) {
        int idx=0;
        for(int i=1;i<v.size();i++)
            if(v[i-1]>v[i]) idx++;
        if(idx>=2) return false;
        if(v.size()>1 and idx)
            return v[v.size()-1]<=v[0];
        return true;
    }
};