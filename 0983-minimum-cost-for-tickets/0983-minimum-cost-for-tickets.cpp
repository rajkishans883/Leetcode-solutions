class Solution {
public:
    int dp[365];
    int count_min(vector<int>&days,vector<int>& costs,int n, int i){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];


        // one - day cost

        int day_1= costs[0]+count_min(days,costs,n,i+1);

        int j=i;
        while(j<n and days[j]<days[i]+7){
            j++;
        }
        int day_7=costs[1]+count_min(days,costs,n,j);
        j=i;
        while(j<n and days[j]<days[i]+30){
            j++;
        }
        int day_30=costs[2]+count_min(days,costs,n,j);
        return dp[i]=min(day_1,min(day_7,day_30));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n= days.size();
        memset(dp,-1,sizeof(dp));
        return count_min(days,costs,n,0);
    }
};