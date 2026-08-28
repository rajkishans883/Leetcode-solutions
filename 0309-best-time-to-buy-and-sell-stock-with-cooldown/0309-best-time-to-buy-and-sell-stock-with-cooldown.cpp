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
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return profit_value(n,0,prices,dp,1);
    }
};