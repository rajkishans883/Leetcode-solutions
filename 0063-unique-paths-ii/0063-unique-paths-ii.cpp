class Solution {
public:

    int totalPath(vector<vector<int>>&matrix,int m,int n,vector<vector<int>>&dp){
        if(m<0 or n<0 or matrix[m][n]==1)return 0;
        if(m==0 and n==0) return 1;

        if(dp[m][n]!=-1)return dp[m][n];

        int top=totalPath(matrix,m-1,n,dp);
        int left=totalPath(matrix,m,n-1,dp);
        return dp[m][n]=top+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return totalPath(matrix,m-1,n-1,dp);
    }
};