class Solution {
public:

    int dfs(vector<int>&prices,vector<vector<int>>&dp,int index,int n,int buy){
        if(index==n)return 0;
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit=0;
        if(buy){
          profit=max((-prices[index]+dfs(prices,dp,index+1,n,0)),(0+dfs(prices,dp,index+1,n,1)));
        }
        else{
           profit=max((prices[index]+dfs(prices,dp,index+1,n,1)),(0+dfs(prices,dp,index+1,n,0)));
        }
        return dp[index][buy]=profit;
    }


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return dfs(prices,dp,0,n,1);
    }
};