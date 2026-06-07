// class Solution {
// public:
    
//     int min_path(vector<vector<int>>&t,int i,int j,int n,vector<vector<int>>&dp){

//         if(i>=n or j>=n)return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         int left=t[i][j]+min_path(t,i+1,j,n,dp);
//         int right=INT_MAX;
//         if(j+1<t[i].size())
//         right=t[i][j+1]+min_path(t,i+1,j+1,n,dp);
        
//         return dp[i][j]=min(left,right);


//     }

//     int minimumTotal(vector<vector<int>>& t) {
//        int len=t.size();
       
//        vector<vector<int>>dp;
//        for (int i = 0; i < len+1; i++) {
//         // Creates a vector of size (i + 1), initialized completely with -1
//         dp.push_back(vector<int>(i + 1, -1));
//     }
//        return min_path(t,0,0,len,dp);

//     }
// };


class Solution {
public:
    // FIX: Added '&' before dp to pass it by reference
    int min_path(vector<vector<int>>& t, int i, int j, int n, vector<vector<int>>& dp){

        if(i == n-1) return t[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        
        // Down move (stays in column j)
        int left = t[i][j] + min_path(t, i + 1, j, n, dp);
        
        // Diagonal move (moves to column j + 1)
        
            int right = t[i][j] + min_path(t, i + 1, j + 1, n, dp); 
        
        
        return dp[i][j] = min(left, right);
    }

    int minimumTotal(vector<vector<int>>& t) {
        int len = t.size();
        
        // Bonus Tip: You can size the rows dynamically using your increasing size trick!
        vector<vector<int>> dp(len);
        for(int i = 0; i < len; i++) {
            dp[i] = vector<int>(i + 1, INT_MAX);
        }
        
        return min_path(t, 0, 0, len, dp);
    }
};