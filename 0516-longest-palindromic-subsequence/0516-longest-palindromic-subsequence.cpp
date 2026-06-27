class Solution {
public:
    int longest_string(string& s1, string& s2, int n1, vector<vector<int>>& dp,
                       int n2) {
        if (n1 < 0 || n2 < 0)
            return 0;

        if (dp[n1][n2] != -1)
            return dp[n1][n2];
        if (s1[n1] == s2[n2]) {
            dp[n1][n2] = 1 + longest_string(s1, s2, n1 - 1, dp, n2 - 1);
        }
        if (s1[n1] != s2[n2]) {
            dp[n1][n2] = max(longest_string(s1, s2, n1 - 1, dp, n2),
                             longest_string(s1, s2, n1, dp, n2 - 1));
        }
        return dp[n1][n2];
    }

    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
       
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <=n; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                if (s1[i-1] != s2[j-1]) {
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};