class Solution {
    int n , m;
    vector<vector<vector<int>>> dp;

    int rec(vector<vector<int>>& grid, int k, int score , int cost,
    int row , int col){

        if(cost > k) return INT_MIN;

        if(row == n-1 and col == m-1){
            int temp = cost + (( grid[row][col] > 0 )?1 : 0);
            if(temp > k) return INT_MIN;
            return grid[row][col];
        }

        if(dp[row][col][cost] != -1) return dp[row][col][cost];

        int currCost = cost + (( grid[row][col] > 0 )?1 : 0);
        if(currCost > k) return dp[row][col][cost] = INT_MIN;

        int down = INT_MIN;
        if(row < n-1 ){
            down = rec(grid, k , score , currCost , row+1 , col);
        }

        int right = INT_MIN;
        if(col < m-1){
            right = rec(grid, k , score , currCost , row , col+1);
        }

        int best = max(down , right);
        if(best == INT_MIN) return dp[row][col][cost] = INT_MIN;

        return dp[row][col][cost] = grid[row][col] + best;
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n , vector<vector<int>>(m , vector<int>(k+1 , -1)));

        int ans = rec(grid , k , 0 , 0 , 0 , 0);
        return (ans < 0 ? -1 : ans);
    }
};