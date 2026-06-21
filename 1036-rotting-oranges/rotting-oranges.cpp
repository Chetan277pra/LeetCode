class Solution {
public:
    int ans = 0;
    int n , m;
    int rec(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& vis)
    {
        if(row < 0 or row >= n or col < 0 or col >= m)
            return INT_MAX;

        if(grid[row][col] == 2)
            return 0;

        if(grid[row][col] == 0 or vis[row][col])
            return INT_MAX;

        vis[row][col] = 1;

        int ans = min({
            rec(grid, row-1, col, vis),
            rec(grid, row+1, col, vis),
            rec(grid, row, col-1, vis),
            rec(grid, row, col+1, vis)  
        });

        vis[row][col] = 0;

        return ans == INT_MAX ? INT_MAX : ans + 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) {
                    int temp = rec(grid , i , j , vis);
                    if(temp == INT_MAX) return -1;
                    ans = max(ans , temp);
                }
            }
        }
        return ans;
    }
};