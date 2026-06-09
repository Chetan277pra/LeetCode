class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(vector<int>& coins, int amount, int ind){
        if(amount == 0) return 0;
        if(amount < 0) return 99999;
        if(ind >= n) return 99999;
        if(dp[amount][ind] != -1) return dp[amount][ind];
        int take = INT_MAX, skip = INT_MAX;

        take = 1 + rec(coins , amount - coins[ind] , ind);
        skip = rec(coins , amount , ind+1);
        
        return dp[amount][ind] = min(take , skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.assign(amount+1 , vector<int>(n , -1));
        int ans = rec(coins , amount , 0);
        return  (ans == 99999 )?-1 : ans;
    }
};