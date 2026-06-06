class Solution {
public:

    int totalPath(int m,int n,vector<vector<int>>&dp){
            if(m<0 or n<0)return 0;
            if(m==0 and n==0)return 1;
            if(dp[m][n]!=-1)return dp[m][n];
            int right=totalPath(m-1,n,dp);
            int left=totalPath(m,n-1,dp);

            return dp[m][n]=right+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return totalPath(m-1,n-1,dp);
    }
};