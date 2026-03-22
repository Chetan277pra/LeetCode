class Solution {
    int ans = -1 ,  n;
    map<int , map<int , int>> dp;
    int rec(vector<int>& nums, int target, int ind, int temp){
        if(ind == n){
            if(temp == target) return 0;
            return INT_MIN;
        }
        if(dp[ind].count(temp)) return dp[ind][temp];
        // include kar
        int take  = rec(nums , target , ind+1 , temp ^ nums[ind]);
        if(take != INT_MIN) take += 1;
        // skip
        int skip = rec(nums , target , ind+1 , temp );
        return dp[ind][temp] = max(take , skip);
    }
public:
    int minRemovals(vector<int>& nums, int target) {
        n = nums.size();
        int ans = rec(nums , target , 0 , 0);
        if(ans < 0) return -1;
        return n - ans;
    }
};