class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> mps,mpt;
        for(auto i:s) mps[i]++;
        for(auto i:t) mpt[i]++;
        for(auto i:mps)
            if(mpt[i.first]!=i.second)return false;
        return true;
    }
};