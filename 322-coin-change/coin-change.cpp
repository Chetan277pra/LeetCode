class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,INT_MAX/10);
        for(int i = 0; i < n; i++)
            dp[0] = 0;
        for(int am = 0; am <= amount; am++){
            for(int i = n-1; i >=0; i--){
                if(am >= coins[i]){
                    dp[am] = min(dp[am] , 1+dp[am-coins[i]]);

                }
                dp[am] = min(dp[am], 1+dp[am] );
            }
        }

        return (dp[amount]==INT_MAX/10 ) ? -1 : dp[amount];
    }
};