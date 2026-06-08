class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        
        int target = total / 2;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return helper(nums, 0, target, dp);
    }

    bool helper(vector<int>& nums, int index, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (index >= nums.size() || target < 0) return false;

        if (dp[index][target] != -1) return dp[index][target];

        // Include or exclude current number
        bool take = helper(nums, index + 1, target - nums[index], dp);
        bool notTake = helper(nums, index + 1, target, dp);

        return dp[index][target] = take || notTake;
    }
};
