class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),j=matrix[0].size();
        int row=-1;
        for(int i=0;i<n;i++){
            if(matrix[i][0]==target or matrix[i][j-1]==target) return true;
            else if(matrix[i][0]<target and matrix[i][j-1]>target) row=i;
        }
        if(row==-1) return false;
        int l=0,r=j-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]>target) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};