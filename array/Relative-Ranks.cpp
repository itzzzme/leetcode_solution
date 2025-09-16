class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp=score;
        sort(score.begin(),score.end(),greater<int>());
        unordered_map<int,int> mp;
        int cnt=1;
        for(auto i:score){
            mp[i]=cnt;
            cnt++;
        }
        int sz=score.size();
        vector<string> ans(sz);
        int j=0;
        for(auto i:temp){
            if(mp[i]==1){
                ans[j++]="Gold Medal";
            }else if(mp[i]==2){
                ans[j++]="Silver Medal";
            }else if(mp[i]==3){
                ans[j++]="Bronze Medal";
            }else{
                ans[j++]=to_string(mp[i]);
            }
        }
        return ans;
    }
};