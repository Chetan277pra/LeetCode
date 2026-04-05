class Solution {
public:
    int n;
    unordered_map<long long, long long> dp;

    long long solve(vector<int>& nums, int i, int k){
        if(k == 0) return 0;
        if(i >= n-1) return 1e15;

        // prune impossible states
        if((n - i) / 2 < k) return 1e15;

        long long key = ((long long)i << 32) | k;
        if(dp.count(key)) return dp[key];

        // skip
        long long res = solve(nums, i+1, k);

        // take
        int need = max(nums[i-1], nums[i+1]) + 1;
        long long cost = max(0, need - nums[i]);

        long long take = cost + solve(nums, i+2, k-1);

        return dp[key] = min(res, take);
    }

    long long minIncrease(vector<int>& nums) {
        n = nums.size();

        // odd case (fixed)
        if(n % 2){
            long long ans = 0;
            for(int i = 1; i < n-1; i += 2){
                int need = max(nums[i-1], nums[i+1]) + 1;
                ans += max(0, need - nums[i]);
            }
            return ans;
        }

        int k = (n-2)/2;
        return solve(nums, 1, k);
    }
};