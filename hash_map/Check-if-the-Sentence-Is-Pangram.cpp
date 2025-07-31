class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> mp;
        for(auto i:sentence) mp[i]++;
        for(char i='a';i<='z';i++)
            if(!mp[i]) return false;
        return true;
    }
};