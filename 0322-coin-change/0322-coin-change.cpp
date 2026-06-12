class Solution {
public:

    int countCoins(vector<int>&coins,int amount,int n,vector<vector<int>>&dp){
        if(n==0){
            if(amount%coins[n]==0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[n][amount]!=-1)return dp[n][amount];
        int nottake=countCoins(coins,amount,n-1,dp);
        int take=1e9;
        if(coins[n]<=amount){
            take=1+countCoins(coins,amount-coins[n],n,dp);
        }
        return dp[n][amount]=min(take,nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0; 
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return countCoins(coins,amount,n-1,dp)==1e9?-1:countCoins(coins,amount,n-1,dp);
    }
};