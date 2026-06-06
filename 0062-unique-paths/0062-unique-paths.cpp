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
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;

        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};