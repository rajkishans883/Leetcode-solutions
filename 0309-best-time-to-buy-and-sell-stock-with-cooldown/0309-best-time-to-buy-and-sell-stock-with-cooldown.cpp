class Solution {
public:


    int profit_value(int n,int i,vector<int>&prices,vector<vector<int>>&dp, int buy){
        if(i>=n){
            return 0;
        }
        int profit=0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        
        if(buy){
            profit=max((-prices[i]+profit_value(n,i+1,prices,dp,0)),(0+profit_value(n,i+1,prices,dp,1)));
        }
        else{
            profit=max((prices[i]+profit_value(n,i+2,prices,dp,1)),(0+profit_value(n,i+1,prices,dp,0)));
        }

        return dp[i][buy]=profit;


    }
    int maxProfit( vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,-0));
        
        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                if(buy){
                    dp[i][buy]=max((-prices[i]+dp[i+1][0]),dp[i+1][1]);
                }
                else{
                    dp[i][buy]=max((+prices[i]+dp[i+2][1]),dp[i+1][0]);
            
                }
            }
        }
        return dp[0][1];
    }
};