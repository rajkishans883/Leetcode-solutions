class Solution {
public:
    int totalSum(vector<int>& nums, int n, int target,
                 vector<vector<int>>& dp) {

        if (n == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (target == 0 || target == nums[0])
                return 1;
            return 0;
        }

        if (dp[n][target] != -1)
            return dp[n][target];

        int notPick = totalSum(nums, n - 1, target, dp);
        int pick = 0;
        if (nums[n] <= target) {
            pick = totalSum(nums, n - 1, target - nums[n], dp);
        }

        return dp[n][target] = notPick + pick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSumOfArray = 0;
        for (auto it : nums) {
            totalSumOfArray += it;
        }
        int countSumWays = 0;
        if(abs(totalSumOfArray)<abs(target)) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(totalSumOfArray + 1, -1));
        if ((totalSumOfArray + target) % 2 != 0 )
            return 0;

        int req = (totalSumOfArray + target) / 2;

        return totalSum(nums, n - 1, req, dp);
        return countSumWays;
    }
};