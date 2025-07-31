class Solution {
public:
    bool isIsomorphic(string s, string t) {
        set<char> st1,st2;
        for(auto i:s)st1.insert(i);
        for(auto i:t)st2.insert(i);
        if(st1.size()!=st2.size()) return false;
        map<char,int> mp;
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();i++){
            if(!mp[s[i]]) mp[s[i]]=(int)t[i];
            if(mp[s[i]]!=(int)t[i])return false;
        }
        return true;
    }
};