class Solution {
public:

    int findSuper(int n1,int n2,string &s1,string &s2,vector<vector<int>>&dp){
        if(n1<0 || n2 <0  )return 0;

        if(dp[n1][n2]!=-1)return dp[n1][n2];

        if(s1[n1]==s2[n2]){
            dp[n1][n2]=1+findSuper(n1-1,n2-1,s1,s2,dp);
        }
        if(s1[n1]!=s2[n2]){
            dp[n1][n2]=max(findSuper(n1-1,n2,s1,s2,dp),findSuper(n1,n2-1,s1,s2,dp));
        }
        return dp[n1][n2];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for( int i=1; i<=n1;i++){
            for ( int j=1 ;j<=n2;j++){

                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout<<dp[n1][n2];

        string s;

        int i=n1;
        int j=n2;

        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    s.push_back(str2[j-1]);
                    j--;
                }
                else{
                    s.push_back(str1[i-1]);
                    i--;
                }
            }
        }

        while(i>0){
            s.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            s.push_back(str2[j-1]);
            j--;
        }
        reverse(s.begin(),s.end());

        return s;
    }
};