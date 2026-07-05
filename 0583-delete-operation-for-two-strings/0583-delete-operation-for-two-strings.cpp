class Solution {
public:
    int longest_palindrom(string& word1, string& word2, int n1, int n2,
                          vector<vector<int>>& dp) {
        if (n1 < 0 || n2 < 0)
            return 0;

        if (dp[n1][n2] != -1)
            return dp[n1][n2];

        if (word1[n1] == word2[n2]) {
            dp[n1][n2] =
                1 + longest_palindrom(word1, word2, n1 - 1, n2 - 1, dp);
        }
        if (word1[n1] != word2[n2]) {
            dp[n1][n2] = max(longest_palindrom(word1, word2, n1 - 1, n2, dp),
                             longest_palindrom(word1, word2, n1, n2 - 1, dp));
        }
        return dp[n1][n2];
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i < n1 + 1; i++) {
            for (int j = 1; j < n2 + 1; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] =
                        1 + dp[i - 1][ j - 1];
                }
                if (word1[i-1] != word2[j-1]) {
                    dp[i][j] =
                        max(dp[i-1][ j ],
                            dp[i][ j - 1]);
                }
            }
        }
        return (n1-dp[n1][n2])+(n2-dp[n1][n2]);
    }
};