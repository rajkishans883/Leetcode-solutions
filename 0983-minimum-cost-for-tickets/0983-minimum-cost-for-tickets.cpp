class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int last_day=days[n-1];
        set<int>st;
        vector<int>dp(last_day+1);
        for(auto it:days){
            st.insert(it);
        }
        dp[0]=0;
        
        for(int i=1;i<=last_day;i++){

            if(st.find(i)==st.end()){
                dp[i]=dp[i-1];
                continue;
            }
            dp[i]=INT_MAX;
            int day_1=costs[0]+dp[max(i-1,0)];
            int day_7=costs[1]+dp[max(i-7,0)];
            int day_30=costs[2]+dp[max(i-30,0)];

            dp[i]=min(day_1,min(day_7,day_30));

        }

        return dp[last_day];

    }
};