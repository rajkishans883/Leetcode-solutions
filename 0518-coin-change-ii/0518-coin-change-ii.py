class Solution:

    def count_ways(self,coins:List[int],amount:int,dp:List[List[int]],n:int)->int:

        if n==0:
            return 1 if amount%coins[0]==0 else 0
        
        if dp[n][amount]!=-1:
            return dp[n][amount]
        nottake=self.count_ways(coins,amount,dp,n-1)
        take=0
        if coins[n]<=amount:
            take=self.count_ways(coins,amount-coins[n],dp,n)
        dp[n][amount]=take+nottake
        return dp[n][amount]

    def change(self, amount: int, coins: List[int]) -> int:
        n=len(coins)
        dp = [[0] * (amount + 1) for _ in range(n)]
        
        for i in range(n):
            dp[i][0]=1

        for i in range(n):
            for j in range(amount+1):
                nottake=dp[i-1][j]
                take=0
                if coins[i]<=j:
                    take=dp[i][j-coins[i]]
                dp[i][j]=take+nottake   
        result=dp[n-1][amount]
        return result

        