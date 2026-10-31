class Solution {
public:
    int n , m;
    int dp[500][500][3];
    int mod = 1e9 + 7;
    int rec(vector<vector<int>>& grid, int i , int j, int last){
        if(i < 0 or j < 0 or i >= n or j >= m) return 0;
        if(i == n-1 and j == m-1) return 1;
        // simple
        if(dp[i][j][last] != -1) return dp[i][j][last];
        int ans;
        if(grid[i][j] == 0){
            // cout << i << " " << j << " 11 " << last << endl;
            ans = (rec(grid , i + 1 , j , 1)%mod + rec(grid , i , j+1 , 2)%mod)%mod;
            
        }
        else{
            // mirror
            // cout << i << " " << j << " 22 " << last <<endl;
            if(last == 1){
                // cout << " down ab right" << i<<" "<< j << endl;
                ans = rec(grid , i , j+1 , 2);
            }
            else if(last == 2){
                // cout << " right ab down "<< i<<" "<< j << endl;
                ans = rec(grid , i + 1 , j , 1);
            }
        }
        return dp[i][j][last] =  ans;;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp , -1 , sizeof(dp));
        return rec(grid , 0 , 0 , 0);
    }
};