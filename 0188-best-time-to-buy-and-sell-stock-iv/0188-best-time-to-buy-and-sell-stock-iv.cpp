class Solution {
public:


    int profit_value(int k,int count,int n,int i,vector<int>&prices,vector<vector<vector<int>>>&dp, int buy){
        if(i>=n or count>=k){
            return 0;
        }
        int profit=0;
        if(dp[i][buy][count]!=-1)return dp[i][buy][count];
        
        if(buy){
            profit=max((-prices[i]+profit_value(k,count,n,i+1,prices,dp,0)),(0+profit_value(k,count,n,i+1,prices,dp,1)));
        }
        else{
            profit=max((prices[i]+profit_value(k,count+1,n,i+1,prices,dp,1)),(0+profit_value(k,count,n,i+1,prices,dp,0)));
        }

        return dp[i][buy][count]=profit;


    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return profit_value(k,0,n,0,prices,dp,1);
    }
};