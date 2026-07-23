class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        // If target is outside the possible range
        if (target > sum || target < -sum)
            return 0;

        int offset = sum;

        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));

        dp[n][target + offset] = 1;

        for (int i = n - 1; i >= 0; i--) {

            for (int cur = -sum; cur <= sum; cur++) {

                int ways = 0;

                // Choose +nums[i]
                if (cur + nums[i] <= sum)
                    ways += dp[i + 1][cur + nums[i] + offset];

                // Choose -nums[i]
                if (cur - nums[i] >= -sum)
                    ways += dp[i + 1][cur - nums[i] + offset];

                dp[i][cur + offset] = ways;
            }
        }

        // Initially current sum = 0
        return dp[0][offset];
    }
};