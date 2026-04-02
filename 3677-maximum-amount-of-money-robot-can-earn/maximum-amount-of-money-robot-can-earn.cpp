class Solution {
public:
    int n , m;
    vector<vector<vector<int>>> dp;
    int rec(vector<vector<int>>& coins, int row, int col, int chance) {
        if (row == m - 1 and col == n - 1){
            if(chance > 0 and coins[row][col] < 0) return 0; 
            return coins[row][col];
        }
        if(dp[row][col][chance] != -76549878) return dp[row][col][chance];
        // down
        int right = INT_MIN;
        if (row < m -1) {
                int liya = INT_MIN;
                int nhiliya = INT_MIN;
                if (coins[row][col] < 0 and chance > 0)
                    liya = rec(coins, row + 1, col, chance - 1);
                // no use of chance
                nhiliya =
                    coins[row][col] + rec(coins, row + 1, col, chance );
            right = max(nhiliya, liya);
        }
        // right
        int down = INT_MIN;
        if (col < n - 1) {
                // no use of chance
                int liya = INT_MIN;
                int nhiliya = INT_MIN;
                if (coins[row][col] < 0 and chance > 0)
                    liya = rec(coins, row, col+1, chance - 1);
                nhiliya =
                    coins[row][col] + rec(coins, row , col+1, chance);
            down = max(nhiliya , liya);
        }
        return dp[row][col][chance] = max(right , down);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        dp.resize(m+1 , vector<vector<int>>(n+1 , vector<int>(3 , -76549878)));
        return rec(coins , 0 , 0 , 2);
    }
};