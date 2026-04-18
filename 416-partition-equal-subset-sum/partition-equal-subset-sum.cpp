class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool rec(vector<int> &nums , int ind , int temp , int sum){
        if(ind == n) return temp == sum;
        if(dp[ind][temp] != -1) return dp[ind][temp];
        int take = 0;
        if(temp + nums[ind] <= sum)
        take =  rec(nums , ind+1 , temp+nums[ind],sum);
        int skip = rec(nums , ind+1, temp , sum);
        return dp[ind][temp] = take or skip;
    }
    bool canPartition(vector<int>& nums) {
         n = nums.size();
        int tot = accumulate(nums.begin() , nums.end() , 0);
         dp.assign(n+1 , vector<int>(tot/2+1 , -1));
        if(tot%2) return false;
        return rec(nums , 0 , 0 , tot/2);
    }
};