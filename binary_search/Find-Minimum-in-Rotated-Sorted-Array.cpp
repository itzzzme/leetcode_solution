class Solution {
public:
    int findMin(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1,ans=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            ans=min(ans,v[mid]);
            if(v[r]-v[mid]<v[mid]-v[l] and v[r]<v[mid]) l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};