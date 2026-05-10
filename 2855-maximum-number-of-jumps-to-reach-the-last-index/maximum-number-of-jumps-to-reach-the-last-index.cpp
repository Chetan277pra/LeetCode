class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(vector<int>& nums, int target, int prev, int ind) {

        if(prev == n - 1)
            return 0;

        if(ind >= n)
            return -1e9;

        if(dp[ind][prev] != -1) return dp[ind][prev];
        

        int take = -1e9;

        if(abs(nums[ind] - nums[prev]) <= target) {

            take = 1 + rec(nums, target, ind, ind + 1);
        }

        int skip = rec(nums, target, prev, ind + 1);

        return dp[ind][prev] = max(take, skip);
    }

    int maximumJumps(vector<int>& nums, int target) {

        n = nums.size();
        dp.assign(n , vector<int>(n , -1));
        int ans = rec(nums, target, 0, 1);

        return ans < 0 ? -1 : ans;
    }
};