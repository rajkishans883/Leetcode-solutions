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
        if(matrix[0][0]==1)return 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        dp[0][0]=1;
        for(int i=1; i< m ; i++){
            if(matrix[i][0]==1){
                dp[i][0]=0;
            }
            else dp[i][0]=dp[i-1][0];
        }

        for(int i=1; i< n; i++){
             if(matrix[0][i]==1){
                dp[0][i]=0;
            }
            else dp[0][i]=dp[0][i-1];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};